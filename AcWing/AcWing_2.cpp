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

// dp问题的基础问题1  01 背包问题
// 每个物品只能选一次   问 总体积不超过V的情况下  如何让价值最大
// f[i][j] 表示 在前i个物品中选 且总体积不超过j的所有选法  存储的属性为 这些选法中总价值的最大值
// 划分依据： 选或者不选第i个物品

const int N = 1010;
int f[N][N];
int vi[N], w[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> w[i];
	}

	//处理边界 可以发现边界都是0 因此特别处理
	// 递归构建
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			if (j >= vi[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - vi[i]] + w[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][v]; 
	return 0;
}