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

// 非常简单的一道问题 由于题目的条件设计的非常严格 而且数组长度非常小  所以我们可以用暴搜的方式解决。
// 构造一个标志数组  如果当前元素对比前一个原始是升序  就为1 否则为0
// 对于一个数组n 从n开始 查看 如果全为1  就直接输出n
// 如果 不全为1  那就减半来看  然后不断减半 直到找到正确的答案。
const int N = 21;
int flag[N];
int s_flag[N]; //方便判断
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1) flag[i] = 1;
			else
			{
				if (a[i] >= a[i - 1]) flag[i] = 1;
				else flag[i] = 0;
			}
		}
		//处理一下前缀和
		for (int i = 1; i <= n; i++) s_flag[i] = s_flag[i - 1] + flag[i];
		//枚举所有可能的结果
		if (s_flag[n] - s_flag[0] == n) cout << n << endl;
		else if (n / 2 != 0 && (s_flag[n] - s_flag[n / 2] == n / 2 || s_flag[n / 2] - s_flag[0] == n / 2)) cout << n / 2 << endl;
		else if (n / 4 != 0 &&
			(s_flag[n] - s_flag[n / 4 * 3] == n / 4
				|| s_flag[n / 4 * 3] - s_flag[n / 2] == n / 4
				|| s_flag[n / 2] - s_flag[n / 4] == n / 4
				|| s_flag[n / 4] - s_flag[0] == n / 4)) cout << n / 4 << endl;
		else if (n / 8 != 0 &&
			(s_flag[n] - s_flag[n / 8 * 7] == n / 8
				|| s_flag[n / 8 * 7] - s_flag[n / 8 * 6] == n / 8
				|| s_flag[n / 8 * 6] - s_flag[n / 8 * 5] == n / 8
				|| s_flag[n / 8 * 5] - s_flag[n / 8 * 4] == n / 8
				|| s_flag[n / 8 * 4] - s_flag[n / 8 * 3] == n / 8
				|| s_flag[n / 8 * 3] - s_flag[n / 8 * 2] == n / 8
				|| s_flag[n / 8 * 2] - s_flag[n / 8 * 1] == n / 8
				|| s_flag[n / 8 * 1] - s_flag[0] == n / 8)) cout << n / 8 << endl;
		else cout << 1 << endl;

	}
	return 0;
}