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

//观察可以得知如果图中有偶数个负数
// 那么必定可以通过 多次操作 实现将图中的所有负数变为正数
// 如果有奇数个负数
// 那么我们可以把负数转移到 绝对值最小的那个元素上
// 这其实就是一种传导的思想  考虑如下的情况
// a ,x ,x ,x ,x ....(n个x) ,b    (如果a b 不在同一行，你可以将直角拉直，变成形如这种的数组)
// 那么可以证明  当 a b都为负数的时候， 必定可以通过题意操作， 挨个将a的负号传递到 b的前一个上去
// 此时 最后一步将 a b 做一次操作 即可将 a b 都变成正数
// 而此操作唯一不起作用的就是  原矩阵中 有奇数个负数，此时可以通过如上操作 将负数转移到绝对值最小的那个数上去 得解。
const int N = 11;
int g[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int res = 0;
		int min_abs = INT_MAX; //记录绝对值最小的那个数
		int cnt_neg = 0;  //记录负数的个数
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> g[i][j];
				if (g[i][j] < 0) cnt_neg++;
				res += abs(g[i][j]);
				min_abs = min(min_abs, abs(g[i][j]));
			}
		}
		if (cnt_neg % 2)
		{
			//说明必定存在一个负数无法变为正
			cout << res - 2 * min_abs << endl;
		}
		else cout << res << endl;
	}
	return 0;
}