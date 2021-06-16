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


// 这道题要转化来看 转换为  从1到n个物品中选， 总体积不超过n的 所有选法的个数
// 那么根据无限背包问题的解法思路  f[i][j]自然就是 从1到i个物品中选， 总体积不超过j的 所有选法的个数
// 那么考虑状态转移 分为两部分， 不选第i个物品 那么就是 f[i-1][j]表示不选
// 如果确定选第i个物品  那么就是   f[i][j-i] 这个保证了至少有一次选择
// 那么选法集合就是 二者相加


// 唯一需要注意的点就是状态的初始化。 当选择的总体积为0，意味着一个物品都不选，这也是一种方案
const int N = 1010;
typedef unsigned long long ULL;
ULL f[N][N];  
const int mod = 1e9 + 7;

int main()
{
	int n;
	cin >> n;

	// 状态初始化  
	memset(f, 0, sizeof f);
	// 0 不存在划分可能 因此
	// 容量为0 的时候 一个不选也是一种方案    这里应当注意到 涉及到 划分方法 一个都不选也是一种划分。。。
	for (int i = 0; i <= n; i++) f[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j - i >= 0) f[i][j] = f[i][j - i] + f[i - 1][j] % mod;
			else f[i][j] = f[i - 1][j] % mod;
		}
	}
	cout << f[n][n] << endl;

	return 0;
}