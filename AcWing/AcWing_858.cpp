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

//Prim算法在某些意义上和 朴素版的dij算法是非常相似的  但是关于dis 和维护的点云s含义不同
// 对Prim算法来说  dis维护的是当前点到点云s中的最短距离 而不是到单源的最短距离 而这个限制也导致 维护的点云s的手法也不一样
// 关于是否存在最小生成树的判断 记住在每次找距离集合最小的边的时候 如果不能找到  就说明结果有问题了。

const int N = 510;
int g[N][N];
int dis[N];
bool st[N];

int n, m;
int res = 0;

bool Prim_MST()
{
	memset(dis, 0x3f, sizeof dis);
	
	for (int i = 1; i <= n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dis[t] > dis[j])) t = j;
		if (i != 1 && dis[t] == 0x3f3f3f3f) return false; //如果找不到到集合不是无穷的边了 那就说明不能生成最小生成树
		if (i != 1) res += dis[t];
		st[t] = true;
		for (int j = 1; j <= n; j++)
		{
			if ( dis[j] > g[t][j])
			{
				dis[j] = g[t][j];
			}
		}
	}
	
	return true;



}


int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = min(g[x][y], z);
	}
	if (Prim_MST()) cout << res << endl;
	else cout << "impossible" << endl;

	return 0;
}