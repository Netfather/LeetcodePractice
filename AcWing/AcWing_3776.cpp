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

// 通过数学不等式推导 这道题类似于线性规划
// 假设 拼盘1 x个  拼盘2 y个
// 目标   e*x + f* y 尽可能大，那么对应x y 本身就尽可能的大
// 同时满足如下约束条件
// x <= a
// y <= min(b,c)
// x + y <= d

// 我们通过枚举x 可以直接确认结果。  首先如果y取到可能的最小值0  那么 x 就是小于等于 min(a,d)
// 即  x 应当从  a,d中较小的那一个取值。
// 所以起始是个枚举 我们遍历所有的x的取值范围即可


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int x = 0;
		int y = 0;
		int res = INT_MIN;
		for (; x <= min(a,d); x++)
		{
			y = min(b, min(c, d - x));
			res = max(res, e * x + f * y);
		}
		cout << res << endl;
	}
	return 0;
}