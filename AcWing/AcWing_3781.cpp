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

// 根据数据量可以判断这道题可以直接模拟
// 由于 ai绝对小于等于m 
// 因此唯一的情况就是 存在某些班级人数  使得  ai + ai+1 + aj <= m 那么这些班可以用一辆车接走
// 而班级又必须按照顺序接走  因此这道题 很简单 两重循环 内层循环负责记录 当次车子的负载情况
const int N = 110;
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];

		int res = 0;

		for (int i = 1; i <= n;)
		{
			int t = m; // 此时车的剩余容量为 m个 
			while ( i <= n &&  t >= a[i])
			{
				t = t - a[i];
				i++;
			}
			res++;
		}
		cout << res << endl;
	}
	return 0;
}