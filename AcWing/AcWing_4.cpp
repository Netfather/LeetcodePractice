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

// 由于时间复杂度不高 因此可以使用三重背包循环
const int N = 110;
int vi[N];
int wi[N];
int si[N];
int f[N][N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i] >> si[i];
	}
	// 当i = 0表示不选任何物品 这时候不存在价值 因此本体不需要初始化
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			for (int k = 0; k <= si[i]; k++)
			{
				// 遍历所有第i个物品可能的选法 从 0 一直到 si[i] 次
				if (j >= k*vi[i]) f[i][j] = max(f[i][j], f[i - 1][j - k * vi[i]] + k * wi[i]);
			}
		}
	}
	cout << f[n][v] << endl;
	return 0;
}