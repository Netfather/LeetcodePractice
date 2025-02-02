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

// 这道题的本质就是 贪心里的区间问题
// 按照如下思路 我们按照左端点排序，然后右端点从小到大
// 如果当前的区间左端点 没有包含在上一次的区间端点中  那么就贪心的选择这一次
// 但是以上思路有一个漏洞  如果有一个区间长度特别小 但是左端点往后考了一格这种 这种方式似乎就会出问题
// 例如 一个区间   排序后 [9,20]  [10,11] [12,13]  按照这种思路 会选择 9,20的 但是很明显 选择后两个明显更优

// 因此 抓住这个问题的核心要点， 那就是 在一个订单结束之前 根本不允许接下一个订单
// 因此要按照右端点从小到大排序， 然后按照左端点从大到小   然后考察所有右端点发生变化的点  考察他们是否满足即可
// 因为  能否接单的关键 取决于你什么时候 能够结束这一单

const int N = 500010;
struct TimeRange
{
	int l;
	int r;

	bool operator < (const TimeRange& w)&
	{
		if (r == w.r) return l > w.l;
		return r < w.r;
	}
}a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].l >> a[i].r;
	}
	sort(a, a + n); //排序
	//遍历搜索一下所有合法的  右端点发生变化的点
	int pre_r = 0; //记录上一次的左右端点
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int cur_l = a[i].l, cur_r = a[i].r;
		if (cur_r != pre_r)
		{
			//说明这次可能可以接单 我们需要考察 起始时间
			if (cur_l > pre_r)
			{
				//可以接单
				res++;
				pre_r = cur_r; //更新数值
			}
		}
	}
	cout << res << endl;

	return 0;
}