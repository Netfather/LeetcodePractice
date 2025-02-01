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

const int N = 310;
int w[N];
int s[N];
int f[N][N];  //表示区间 i到 j 合并为一个堆的所有合并方法 代价的最小值
// 考虑转移方程   假定中间有个k 将ij划分成两部分，则  总代价为  f[i][k] + f[k + 1][j] + s[j] - s[i - 1]

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i], s[i] = s[i - 1] + w[i];
	memset(f, 0x3f, sizeof f);
	// 考虑边界情况 如果 f[0]表示区间1到0 合并为一个堆的代价 此时不存在 因此为0
	for (int i = 0; i <= n; i++) f[i][i] = 0;

	// 区间合并题目的模板枚举，先枚举长度 再枚举左端点，切记！！！！
	for (int len = 1; len <= n; len++)
	{
		//枚举左端点
		for (int i = 1; i <= n; i++)
		{
			int j = i + len;
			if (j <= n)
			{
				for (int k = i; k < j; k++)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
				}
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}