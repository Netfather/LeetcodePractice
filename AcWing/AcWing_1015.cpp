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
//此题是很基础的dp问题，我们可以很明显的得到结论，当你站在网格中的某个点，你的最大值只可能来自你左边和上面中的较大的那个


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c; //行数，列数
		vector<vector<int>> dp(r + 1, vector(c + 1, 0));
		//dp状态数组 用于存储当你处于i，j位置时候，你当前能取得的最大花生数
		//由于边界条件全为0，因此这里不需要进行边界初始化
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				int tmp;
				cin >> tmp;
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + tmp;
			}
		}
		cout << dp[r][c] << endl;
	}
	return 0;
}