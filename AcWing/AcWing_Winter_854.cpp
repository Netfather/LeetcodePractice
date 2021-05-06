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

// Floyd算法是用于求解 多源汇问题的唯一解法，过程非常简单，所用的思想也是dp的思想
// 维护好一个 数组 w[i][j][k] 这个k表示 不超过k个点 也就是当前路径上不超过k个点的值
// 由于时间复杂度比较糟糕，这种只适用于稠密图
const int N = 210;
int g[N][N];
int n, m, k;

void floyd()
{
	// 遍历n个顶点
	for (int k = 1; k <= n; k++)
	{
		// 遍历起点
		for (int i = 1; i <= n; i++)
		{
			//遍历终点
			for (int j = 1; j <= n; j++)
			{
				//尝试更新
				if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
			}
		}

	}
}


int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	floyd();
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		if (g[x][y] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << g[x][y] << endl;
	}
	return 0;
}