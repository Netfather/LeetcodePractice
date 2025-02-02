//思路：

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <climits>
using namespace std;

//spfa 和 堆i优化的dij非常的相似 但请牢记如下几点不同
// 点云的维护 spfa的st是为了表明一个点是否已经在队列里   dij的st是表明当前这个点是否已经同化 同化过的不需要再次考虑
// 队列的种类 spfa的队列就是普通的队列， dij的队列是优先队列 是通过距离更新的


//spfa本质是 bell-ford算法的优化  回想 bellman算法 其实遍历所有的边是一个没有必要的操作，因为有些边和源点是不连通的，
//因此从本质来说 这些点是完全不用更新的  考虑到这点观察，spfa算法将bfs的思想融入其中
// 类似于 dij算法的堆优化版本，使用一个队列来维护之前更新过的前驱节点，然后使用更新过的点来更新现在的点

// 与堆优化版本的dij算法相比 这个spfa的区别在于    其中第一点区别尤为重要  dij的点云s是只会维护一次的 只要你加入了 就永远无法推出
//1] Dijkstra算法中的st数组保存的是当前确定了到源点距离最小的点，且一旦确定了最小那么就不可逆了(不可标记为true后改变为false)；
//SPFA算法中的st数组仅仅只是表示的当前发生过更新的点，且spfa中的st数组可逆(可以在标记为true之后又标记为false)。
//顺带一提的是BFS中的st数组记录的是当前已经被遍历过的点。
//2] Dijkstra算法里使用的是优先队列保存的是当前未确定最小距离的点，目的是快速的取出当前到源点距离最小的点；
//SPFA算法中使用的是队列(你也可以使用别的数据结构), 目的只是记录一下当前发生过更新的点。

// 但是这个spfa算法 有一点致命的缺陷在于 他不允许出现负权回路，因为一旦出现负权回路 同样会使循环陷入死循环

//由于数据是稀疏图 因此不适合使用bellman算法来做
const int N = 1000010;
int e[N], ne[N], w[N], h[N];
int idx; //地址分配器

void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

int n, m;
int dis[N];
int st[N]; //这个st 和 dij中的点云s有着本质的区别   这里的st是为了表明这个点是否已经在队列中了
typedef pair<int, int> PII;

int spfa()
{
	//初始化距离 
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;

	//初始化队列  注意这里不是优先队列 而是队列而已
	queue<int> q;
	q.push(1); //1号端点的距离为0

	//注意这一步就和heap_dij有着显著的区别  在heap版中 这里是不需要手动加入的 所有的全部融合在 次数为n次的循环中
	st[1] = true; // 用于表示 1好点已经入队了


	while (q.size())
	{
		auto key = q.front();
		q.pop();
		
		int key_index = key;
		//此时这个点从队列中拿出 标记一下
		st[key_index] = false;

		//处理所有和这个点关联的点
		for (int i = h[key_index]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//尝试更新
			if (dis[index] > dis[key_index] + weight)
			{
				//只要发生变化 就一定要更新
				dis[index] = dis[key_index] + weight; 
				//更新成功  而且这个点不在队列中  在heap中优先队列的冗余是通过st来进行处理的 
				// 而spfa算法中 这个部分是根据st来计算的，如果一个点已经在队列中 哪怕后续的结果再小 都不能在本次更新
				if (!st[index])
				{
					q.push( index );
					st[index] = true;
				}
			}
		}
	}
	if (dis[n] == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << dis[n] << endl;
	return 0;
}



int main()
{
	memset(h, -1, sizeof h);

	cin >> n >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	spfa();

	return 0;
}