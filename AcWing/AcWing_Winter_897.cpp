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

//最最最经典的dp问题 维护这样一个dp集合
// dp[i][j] 表示 A字符串 从 1到i的子串 和 B字符串从1到j的子串  两个子串的所有公共子序列   属性为长度的最大值
// 考虑状态转移
// 如果我们不选第i个位置， 那么 结果为  dp[i-1][j]
// 如果我们选第i个位置 那么 我们就要在B中 从1到j寻找 找到所有 的k 使得 B[k] = A[i] 然后max( dp[i-1][k-1] + 1)
// 但是这个做法会爆时间复杂度，那么我们可以优化亿点点， 由于 我们在上一个做法中是把所有的k都找出来了 这起始是没必要的
// 我们只需要从 j位置往前扫，找到第一个与A[i]相等的点， 再往前的点都是重复的子问题，不需要考虑。这样时间复杂度最差才是O{n三方}



// 但是 但是 我们也可以不用划分的这么细，充分利用重叠子问题的特性
// 直接考虑  如果 Ai == Bj 那么必选  如果两个不相等，考虑不要i 或者不要j  这样时间复杂度会降低的很低很低

const int N = 1010;
int dp[N][N];

int main()
{
	int n, m;
	cin >> n >> m;
	string A, B;
	cin >> A >> B;
	A = "?" + A;
	B = "?" + B;

	//初始情况  考虑 dp[0][0]的情况，此时A,B为空集不存在长度 为0 因此不需要初始化
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//先处理不选i的情况
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			//如果选择i
			for (int k = j; k >= 0; k--)
			{
				if (B[k] == A[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + 1);
					break;
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}