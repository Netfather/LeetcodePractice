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

// bellman-ford算法   非常简单
//for n次
//for 所有边 a, b, w(松弛操作)
//dist[b] = min(dist[b], back[a] + w)
//使用back的根本原因就在于 你不能用这次更新过的距离 再来更新这次 这回导致点与点之间的更新不同步
//注意：back[] 数组是上一次迭代后 dist[] 数组的备份，由于是每个点同时向外出发，
//因此需要对 dist[] 数组进行备份，若不进行备份会因此发生串联效应，影响到下一个点

// 牢记 当是单源最短路径 然后存在负权边  然后是稠密图的时候  就可以使用bellman-ford算法
// 由于bellman-ford算法的时间复杂度非常糟糕 这种算法 只能用来处理图的规模非常小的情况
int n, m, k;
const int N = 10010;
int dis[N];

struct Edges
{
	int a;
	int b;
	int w;
}edges[N];


void bellfold()
{
	//初始化距离
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	int back[N]; //设定备份数组

	for (int i = 0; i < k; i++)
	{
		//备份本次
		memcpy(back, dis, sizeof dis);
		for (auto key : edges)
		{
			//遍历所有的边 
			if (dis[key.b] > back[key.a] + key.w)
			{
				//更新成功  注意 更新的位置 在本次的dis 但是a的位置 只能使用上一次的数值以保证同步
				dis[key.b] = back[key.a] + key.w;
			}
		}
	}
	//由于负权边的问题 导致无法达到的点 也可能小于0x3f3f3f3 因此这里提供一个经验值
	if (dis[n] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dis[n] << endl;
}

int main()
{
	cin >> n >> m >> k;

	while (m--)
	{
		cin >> edges[m].a >> edges[m].b >> edges[m].w;
	}


	bellfold();
	return 0;
}