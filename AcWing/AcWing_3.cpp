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

const int N = 1010;
int f[N][N];
int vi[N];
int wi[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i];
	}

	// 当不选任何物品的时候  对应的总机制为0 因此不需要初始化
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			// 先考虑 不选第i个的情况
			f[i][j] = max(f[i - 1][j], f[i][j]);
			// 再考虑 至少选第i给  1次的情况
			if (j >= vi[i])
			{
				f[i][j] = max(f[i][j - vi[i]] + wi[i], f[i][j]);
			}
		}
	}
	cout << f[n][v] << endl;

	return 0;
}