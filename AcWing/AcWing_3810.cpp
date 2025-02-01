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

//  一天分为n个时段   由于连续休息时间可能跨天  其实我们只需要 将两个天拼接在一起  然后
// 从每天的第一个 10 之后开始统计 一直统计到 第二天的第一个  10 交界处即可

//非常简单的模拟题
const int N = 400010;
int w[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		// 先找到第一个 10交汇点
		int flag = 0;
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			if (flag == 0 && i != 0 && w[i - 1] == 1 && w[i] == 0) p = i, flag = 1;
		}
		// 延长一天的时间
		for (int i = n; i < n + p; i++)
		{
			w[i] = w[i - n];
		}
		// 在 p到 n+p的时间内  寻找最长的休息时间
		int res = INT_MIN;
		int tempres = 0;
		for (int i = p; i < n + p; i++)
		{
			if (w[i] == 1) tempres++;
			else
			{
				res = max(res, tempres);
				tempres = 0; //清空
			}
		}
		cout << max(res, tempres) << endl;

	}


	return 0;
}