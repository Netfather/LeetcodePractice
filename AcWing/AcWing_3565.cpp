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

// 由于最终的矩阵是一个所有行和所有列都是回文序列的矩阵，因此将矩阵划分为1/4  然后遍历这1/4矩阵
// 找到对应的三个点，因此这道题就变成 求问到四个点距离最小的距离是多少？ 等效于货舱选址问题。
// 好吧 这道题这个思路是错误的   
// 漏洞在于   货舱选址并不等效于求平均数  因为距离的最小值是中位数！！   是排好序后的中间一个值

//正确题解


const int N = 110;
long long g[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> g[i][j];
		//开始遍历左上的1/4区域  如果是奇数 那么中间这一行对应的3个点其实就是他自己，是不需要变化的
		long long  res = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = 1; j <= m / 2; j++)
			{
				//找到对应的其余三个点
				int right_up_i = i, right_up_j = m - j + 1;
				int left_down_i = n - i + 1, left_down_j = j;
				int right_down_i = n - i + 1, right_down_j = m - j + 1;
				vector<long long> q;
				q.push_back(g[right_up_i][right_up_j]);
				q.push_back(g[left_down_i][left_down_j]);
				q.push_back(g[right_down_i][right_down_j]);
				q.push_back(g[i][j]);
				sort(q.begin(), q.end());
				for (auto i : q) res += abs(i - q[q.size() / 2]);
				q.clear();
			}
		}
		//特判一下中间那个线
		if (n % 2 && m % 2)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				long long ave = (g[i][m / 2  + 1] + g[n-i+1][m/2 + 1]) / 2;
				res += (abs(ave - g[i][m / 2 + 1]) + abs(ave - g[n - i + 1][m / 2 + 1]));
			}
			for (int j = 1; j <= m / 2; j++)
			{
				long long ave = (g[n/2 + 1][j] + g[n/2 + 1][m-j+1]) / 2;
				res += (abs(ave - g[n / 2 + 1][j]) + abs(ave - g[n / 2 + 1][m - j + 1]));
			}
		}
		else if (n % 2)
		{
			for (int j = 1; j <= m / 2; j++)
			{
				long long ave = (g[n / 2 + 1][j] + g[n / 2 + 1][m - j + 1]) / 2;
				res += (abs(ave - g[n / 2 + 1][j]) + abs(ave - g[n / 2 + 1][m - j + 1]));
			}
		}
		else if (m % 2)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				long long ave = (g[i][m / 2 + 1] + g[n - i + 1][m / 2 + 1]) / 2;
				res += (abs(ave - g[i][m / 2 + 1]) + abs(ave - g[n - i + 1][m / 2 + 1]));
			}
		}
		cout << res << endl;;
	}

	return 0;
}