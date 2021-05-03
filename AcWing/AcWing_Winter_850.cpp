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


// 但是如果边数和点数都很大的情况下  就需要使用优先队列来进行 
// 因为朴素dij算法中 最致命的问题就在于， 每次找到 不在s中的  距离最近的点 消耗的时间实在是太长了
// 因此这里考虑使用优先队列的方式， 我们维护优先队列，每当更新了距离 我们就把那个对应的点和距离入队，然后进行计算

//由于是稀疏图 这里使用邻接表存储
const int N = 1000010;
int e[N], h[N], w[N], ne[N], idx;
int d[N];
bool st[N]; //用于表示这个点是否已经在点云s中了
typedef pair<int, int> PII;
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}


int heap_dijstra()
{
	//首先修正距离
	memset(d, 0x3f, sizeof d);
	d[1] = 0; // 1号顶点的距离为0

	//定义小根堆
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 }); //由于必须要让距离在前 才可以根据距离来判定  因为小根堆默认是以 首元素作为排序对象的

	while (heap.size())
	{
		auto k = heap.top();
		heap.pop();
		int ver = k.second;  // 这里只需要拿出顶点就可以了   dis 已经可以根据 d[ver] 进行索引了
		// 	这里要多一步，由于小根堆会存在冗余备份，因此如果弹出的元素已经在s中了 我们就直接跳过
		if (st[ver]) continue;
		st[ver] = true;

		//拿这个点更新一下他联通的所有点
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//这两个分别表示 这个ver所连接的  边权和对应的顶点编号
			//然后尝试更新
			if (d[index] > d[ver] + weight)
			{
				//说明可以更新
				d[index] = d[ver] + weight;
				heap.push({ d[index],index });
			}
		}
	}
	if (d[n] == 0x3f3f3f3f) return -1;
	return d[n];
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int t = heap_dijstra();

	cout << t << endl;

	return 0;
}