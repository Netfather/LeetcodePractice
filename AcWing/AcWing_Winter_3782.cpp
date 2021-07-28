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

// 如果使用最直接的暴力解法  时间肯定会超时
// 注意到 题目中说明不保证所有点的位置各不相同
// 因此这里 应该先 排一个序  然后去重  之后 再 统计每个序列出现过几次
// 之后只需要对出现一次的坐标统计就可以了。
// 同时注意到  是先平方再求和 因此 我们完全可以把 x 和 y 独立来看


// 上述方法同样超时  那只能使用vector容器组  这样可以不用排序  直接在O(n)时间内实现去重和 次数

// 修正使用了 unorderd还是超时 根据提示的推公式来看
// 应该是 使用公式推到的方式 首先距离和公式可以分为  平方和部分 和 交错乘积部分
// 平方和部分在读入数据的时候就可以直接算好   问题在于 交错乘积部分
// 通过一定样例的推导 我们可以发现 交错成绩部分其实是  从 首元素1开始一直到 n-1  满足如下公式  x[i] * (s_x[n] - s_x[i])
// 这样也可以在O(n) 时间内 得到结果

// 最终这道题解决了  由于数据有正有负  为了避免这个方法爆LL  需要用到ULL 而数据有正有负
// 所以我们将原始数据  加上一定的偏移量 由于数据 本身所求的是  相对距离的平方和 所以所有坐标整体偏移对最终结果是没有影响的

typedef unsigned long long ULL;
const int N = 100010;
ULL x[N];
ULL y[N];
ULL s_x[N];
ULL s_y[N];

int main()
{
	ULL res = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		x[i] += 10001;
		y[i] += 10001;
		res += (n - 1) * x[i] * x[i];
		res += (n - 1) * y[i] * y[i];
		s_x[i] = s_x[i - 1] + x[i];
		s_y[i] = s_y[i - 1] + y[i];
	}

	for (int i = 1; i < n; i++)
	{
		res -= 2 * x[i] * (s_x[n] - s_x[i]);
		res -= 2 * y[i] * (s_y[n] - s_y[i]);
	}


	cout << res << endl;

	return 0;
}