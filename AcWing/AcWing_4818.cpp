//思路：
// 预处理一个 moeny数组  数组的索引为 收取学费的值
// money[ci] 表示当收取 ci的学费时 有多少头奶牛是愿意支付价格的
// 但是由于一开始是ci是乱序的  无法在O(n)时间内处理出moeny数组
// 所以应该先排序  然后遍历一遍即可 时间复杂度为 nlgn

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

const int N = 100010;
typedef unsigned long long LL;
LL res = 0;

int main()
{
	int n;
	cin >> n;
	vector<LL> w(n, 0);
	int res_2 = 0;
	for (int i = 0; i < n; i++) cin >> w[i];
	//Quick_Sort(0, n - 1);
	sort(w.begin(), w.end());

	for (int i = 0; i < n; i++)
	{
		LL tmp = w[i] * (n - i);
		if (res < tmp)
		{
			res = tmp;
			res_2 = w[i];
		}
	}
	cout << res << " " << res_2;
	return 0;
}