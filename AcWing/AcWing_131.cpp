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

//非常经典的求直方图中最大矩形的题目 最早在leetcode中见到
// 思路是枚举  我们把当前所在的直方图作为最小值，往左右延展 尝试找到 所能够达到的最大距离。 然后枚举每个元素就可以找到最大值。
// 所以这道题要首先预处理出 两个数列 分别代表 某个元素往左比他小的第一个元素  和 某个元素往右比他小的第一个元素
// 约定 -1 表示找不到 可以一直取到表头或表尾
typedef unsigned long long ULL;
int n;
const int N = 1000010;
ULL w[N];  //注意柱形图高度很大 有可能爆int
int r[N];
int l[N];


int main()
{
	while (cin >> n && n != 0)
	{
		memset(w, 0, sizeof w);
		ULL res = 0;
		for (int i = 0; i < n; i++) cin >> w[i];
		//预处理左边比他小的第一个元素
		stack<int> s;  //存储的是数据的下标
		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && w[s.top()] >= w[i]) s.pop();
			if (s.empty()) l[i] = -1;
			else l[i] = s.top();
			s.push(i);
		}
		// 预处理右边比他小的第一个元素
		stack<int> s_r;
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s_r.empty() && w[s_r.top()] >= w[i]) s_r.pop();
			if (s_r.empty()) r[i] = -1;
			else r[i] = s_r.top();
			s_r.push(i);
		}

		// 枚举每个元素
		for (int i = 0; i < n; i++)
		{
			ULL tmp = 0;
			// 这里之所以不处理 l[i] == -1的情况就在于 这时候-1正好减去这个坐标 等效于加1  没有问题
			if (r[i] == -1) tmp = (n - l[i] - 1) * w[i];
			else tmp = (r[i] - l[i] - 1) * w[i];
			res = max(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}