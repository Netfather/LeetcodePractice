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

//从题目的意思来看  由于指定的时刻 不能等于ai  所以 指定的时刻必定为整数
// 那么考虑到这一点 我们来考虑让亮灯时间尽可能长的 可能点在于
//  1. 所有可能的选点必定是 ai -1 或者 ai + 1为止 通过反证法可以证明
//  2. 如何在O(1)的时间内得到 亮灯总时长
// 

// 观察如下样例
// 对于一个 a1到a6的划分    正常时间是
// 0,a1   a2,a3   a4,a5
//而如果将x加入到 0,a1之间 就会变成
// 0,x  a1,a2 a3,a4 a5,a6 这样  所以这道题 可以先预处理出两个前缀和数组
// 一个负责记录 0到a1这种  另一个负责记录 a1到a2这种

// 然后剩下的就是枚举  遍历 所有可能取到的位置  接着用前缀和数组 在O(1)时间内得到亮灯总时长

const int N = 100010;
typedef unsigned long long ULL;
ULL res = 0; //记录每一次的结果
int a[N]; //单一时刻表 从0开始记录
unordered_set<int> Table; //用于记录想要指定的时刻 是否已经存在了
ULL s1[N]; //前缀和数组 从1开始 一次记录  0,a1  a2,a3这种时刻的差
ULL s2[N]; //前缀和数组 从1开始 每一次记录 a1,a2 a3,a4 这种时刻的差

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, M;
		cin >> n >> M;
		for (int i = 1; i <= n; i++) cin >> a[i], Table.insert(a[i]);
		Table.insert(0);
		Table.insert(M);
		a[n + 1] = M; //哨兵  防止数组越界

		// 1. 预处理前缀和  这里也可以直接把 0 和 M加入到a中 这样就不需要特判这么多情况了
		int p1 = 1, p2 = 1;
		for (int i = 1; i <= n; i++)
		{
			// 记录形如 0,a1 a2,a3  a4,a5的区间
			if (i % 2)
			{
				//如果i是奇数
				//特判一下起始状态
				if (i == 1) s1[p1] = s1[p1 - 1] + (a[i] - 0);
				else s1[p1] = s1[p1 - 1] + (a[i] - a[i - 1]);
				p1++;
			}
			// 记录形如 a1,a2 a3,a4  a5,a6的区间
			else
			{
				s2[p2] = s2[p2 - 1] + (a[i] - a[i - 1]);
				p2++;
			}
		}
		// 处理一下尾巴
		if (n % 2)
		{
			//如果n是奇数
			s2[p2] = s2[p2 - 1] + (M - a[n]);
			p2++;
		}
		else
		{
			s1[p1] = s1[p1 - 1] + (M - a[n]);
			p1++;
		}

		// 元素检查
		//for (int i = 1; i < p1; i++) cout << s1[i] << " ";
		//cout << endl;
		//for (int i = 1; i < p2; i++) cout << s2[i] << " ";
		//cout << endl;
		//cout << endl;

		// 2. 然后开始枚举搜索
		//枚举一下 s1 数组  在S1数组中枚举意味着 是否在某个时刻做出开关灯操作。
		// 除了i=1的情况下 由于不能为负数 只有一种情况以外    其他情况都是有两种情况的
		res = s1[p1-1] - s1[0]; //此时res为不拨动开关的选择
		ULL tmp = 0;
		for (int i = 1; i < p1; i++)
		{
			tmp = s1[i - 1] - s1[0] + s2[p2 - 1] - s2[i - 1];
			//特判一下  如果是刚开始 0,a1阶段 此时 
			if (i == 1)
			{
				if (!Table.count(1)) tmp += (a[1] - 1);
			}
			else
			{
				//这里的下标  手动模拟一下就能推导出来 
				// 对于si中的第i个数据   他对应在原数组中的范围 就是 2*i -1 
				if (!Table.count(a[2 * i - 1] - 1)) res = max(res, tmp + (a[2 * i - 1] - 1 - a[2 * i - 2]));
				if (!Table.count(a[2 * i - 3] + 1)) res = max(res,tmp+(a[2 * i - 2] - (a[2 * i - 3] + 1)));
			}
			res = max(res, tmp);
		}
		cout << res << endl;
		res = 0;
		memset(s1, 0, sizeof s1);
		memset(s2, 0, sizeof s2);
		Table.clear();
	}
	return 0;
}