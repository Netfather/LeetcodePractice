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

//1. 首先我们找到一个字符串中 两个数字各不相同的位置  如果存在解，那么起始位置必定是从这个地方开始的
// 2. 然后考虑维护一个如下的数据结构
// 3. 一个记录位置开始   一个记录寻找的数字    记录位置开始的地方实时维护一个起始位置的最大值
// 4. 这样我们就能用O(N)的时间完成这道题了

int Table[4]; //用于记录该位置的最大值
// 例如对于这样一个字符串  1123   在扫描到12的时候  会记录如下 Table[3] = 1, 这告诉我们当遇到3的时候，将下标 - 1 + 1就是我们所求
// 然后为了避免出现问题，首先将Table初始化一个负无穷的距离，然后每次更新一下即可

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		string a;
		cin >> a;

		int res = INT_MAX;
		memset(Table, -0x3f, sizeof Table);
		int i = 0;
		for (; i < a.length() - 1; i++)
		{
			// 拿到  这个数 和后一个数代表的 数字
			int x = a[i] - '0';
			int x_1 = a[i + 1] - '0';
			// 如果这两个数字不相等，说明找到一个起始位置，放入Table中。同时根据单调栈思想
			// 之前放入的 同样位置的数字已经完全没用了，所以可以直接覆盖
			if (x != x_1)
			{

				//发现位置
				Table[6 - x - x_1] = i;
			}
			res = min(res, i - Table[x] + 1);
		}
		//处理最后一个数，处理一下没遍历到的最后一个数字
		res = min(res, i - Table[(a[i] - '0')] + 1);
		// 如果res 比 a的长度还要长 说明结果不存在  Table从头到尾都没有更新过
		if (res > a.length()) cout << 0 << endl;
		else cout << res << endl;
	}


	return 0;
}