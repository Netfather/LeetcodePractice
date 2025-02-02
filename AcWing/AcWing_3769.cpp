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

// 考虑如下情况 如果只有三个箱子，  如果一个一个运 把后两个箱子时候放入1号箱子要 3步操作
// 但是如果 从3到2  再从2到1 只需要2步操作即可。并且这种操作必定是最优操作
// 那么推广到 n种箱子的情况，可以得到结论： 最大可能的操作 必定是从最远处 积累在一起再运送过来的。
// 并且  没有其他操作比这种操作的性价比更高。 因此  的解


// 以上错误  题目每次移动 只能移动 1个石头
// 这种情况下   考虑如下式子   将 a2箱子内石头完全移动到a1 需要消耗 1* a2的操作
// 因此将 an箱子极其之前的所有箱子石头完全移动到a1 需要消耗 1*a2 + 2 * a3 + 3 * a4 + .... + (n-1) * an 操作
// 如果某个n使得 恰好等于 d  那么 a2 + a3 到 an就为答案
// 如果某个n 使得  有 f(n-1) < d < f(n) 那么答案就为多出来的数字 / an的整数

const int N = 110;
int a[N];
int s[N]; //处理一下前缀和

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}

		//遍历一下找到满足题意的fn
		int fn = 0;
		int p = 2;
		for (; p <= n; p++)
		{
			fn += (p - 1) * a[p];
			if (fn >= d) break;
		}
		if (fn == d) cout << s[p] - s[0] << endl;
		else if (fn > d) cout << s[p - 1] - s[0] + (d - (fn - (p - 1) * a[p])) / (p - 1) << endl;
		else
		{
			//否则说明 没有通过break 出来  全部遍历完成了
			cout << s[n] - s[0] << endl;
		}

		//

	}

	return 0;
}