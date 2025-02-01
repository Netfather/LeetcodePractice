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

// 直接暴搜就可以了  长度为5000  T为100 时间复杂度为10的5次方 可以过
// 暴力搜索 回文序列的中轴线即可
// 以上思路错误， 由于子序列可以不连续 因此对于奇数个子序列的情况，我们只需要找到任意两个不连续的相等数字即可
// 对于偶数个子序列的情况，我们可以发现 我们也只需要找到任意两个不连续的相等数字即可
// 因此这个问题退化为， 我们能否找到 任意两个不连续的相等数。
// 子序列可以不连续  可以跳着选  那么如果存在长度为3的子序列 只需要存在两个不连续的相等数即可
const int N = 5010;
int w[N];
int Loc[N]; //用于存储某个数在w中的位置是哪个 从1开始计数

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(Loc, 0, sizeof Loc);
		bool is_valid = false;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			if (!Loc[w[i]]) Loc[w[i]] = i + 1; //如果w[i]的位置没有被记录过，那么就记录一下
			else if (Loc[w[i]] + 1 != i + 1) is_valid = true; //如果被记录过 而且两个位置不连续，那么就证明找到了
			// 如果两个位置连续，我们就不需要修改 因为保证Loc尽可能和现在的指针i尽可能的远  就越可能找到
		}
		if (is_valid) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}