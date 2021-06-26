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

int l, r;
typedef unsigned long long ULL;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> l >> r;
		int k = r;

		//当k位于上确界的时候， 查看分的最大的情况
		ULL tmp = ULL((2 * l) / (2 * k + 1));
		if (tmp >= float((r + 1) / (k + 1)))
		{
			cout << "YES" << endl;
			continue;
		}

		// 当k位于下确界的时候，查看分的最大的情况
		k = 0;
		tmp = ULL((2 * l));
		if (tmp >= (r + 1))
		{
			cout << "YES" << endl;
			continue;
		}
		// 上下确界都无法满足题意，说明必定不存在满足题意的点 则输出结果
		cout << "NO" << endl;
	}
return 0;
}