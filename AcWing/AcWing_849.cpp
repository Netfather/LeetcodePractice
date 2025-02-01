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


// dij算法的核心就在于 维护一个点云s  这个s标志着成功同化的类型。 
// 每次都从不在s的点中 选择一个 距离s最近的点，通过三角不等式比较 距离，然后将这个点加入到s 进行维护。
// 这道题 点数范围为500 边数范围为10的5次方  是稠密图 不适合使用邻接表形式，而应该使用临界矩阵形式存储

const int N = 510;
int g[N][N];
int d[N];   //用于表示   1号点 到 索引小标点 的最短距离
bool st[N]; //表示这个点是否已被同化
int n, m;

int dijstra()
{
	// 首先初始化 将1号点加入同化 并标记距离
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	//固定的  dij算法一定会将所有点遍历一次  由于1号点已经遍历过 因此总共一定需要遍历 n-1次
	for (int i = 0; i < n; i++)
	{
		int t = -1;   //用于找到 不在s中 而且距离1号点距离最近的点
		for (int j = 1; j <= n; j++)
		{
			if (st[j] == false && (t == -1 || d[j] < d[t])) t = j;
		}
		// 找到点 然后开始同化
		st[t] = true;  //标志这个点 已经是我们已经检查过 准确找到 最小值的点了 
		// 然后拿这个点的距离来更新一下所有其他点的距离。
		for (int j = 1; j <= n; j++)
		{
			// 由于新点的加入 因此 唯一导致不在s中的其他点发生变化的因素就在于，是否经过t点
			d[j] = min(d[j], d[t] + g[t][j]);
		}
	}
	if (d[n] == 0x3f3f3f3f) return -1;  //如果第n个点路径为无穷大即不存在最低路径
	return d[n];
}



int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);    //初始化图 因为是求最短路径
								//所以每个点初始为无限大
	while (m--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		//由于题目可能存在重边和自环  因此需要在这里剔除会导致两点距离变大的重边
		g[a][b] = min(g[a][b], w);
	}

	int res = dijstra();

	cout << res << endl;
	return 0;
}