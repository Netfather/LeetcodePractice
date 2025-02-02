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

// 0 或 1   1表示这一天是上课日   0 表示是休息日

// 首先考虑  第一个上课日 和 最后一个上课日  
// 将数组截断   这两个前后的 所有日子都不用考虑
const int N = 110;
int w[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i];
		//搜索第一个上课日
		int start = 0;
		for (int i = 0; i < n; i++)
		{
			if (w[i] == 1)
			{
				start = i;
				break;
			}
		}
		//搜索最后一个上课日
		int end = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (w[i] == 1)
			{
				end = i;
				break;
			}
		}
		//找到之后 检查一下
		int res = 0; 
		int cnt_zero = INT_MAX; //统计两个1之间 0的个数
		if (start > end) cout << 0 << endl;
		else
		{
			for (int i = start; i <= end; i++)
			{
				if (w[i] == 1)
				{
					if (cnt_zero == 1) res++; //当且仅当中间为一个1的时候 需要额外多待一天
					res++;
					cnt_zero = 0; //重置数量
				}
				else cnt_zero++;
			}
			cout << res << endl;
		}
	}
	return 0;
}