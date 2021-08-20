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

//货舱选址问题的高难度变种 在货舱选址中  其实条件就是  ai - t的绝对值 <= 0 而现在变成了1
// 这意味着 对于中间的地址 其实有更高的裕度  这也就意味着  我们需要考察中位数前后 一共三个不同的数字 观察其中使得代价最小的组合即可
const int N = 1010;
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
		if (n == 1)
		{
			cout << w[0] << " " << 0 << endl;
			continue;
		}

		sort(w, w + n);
		int t = 0;
		int res = INT_MAX;

		int bind = w[n / 2] - 1;
		for (; bind <= w[n / 2] + 1; bind++)
		{
			int tempres = 0;
			for (int i = 0; i < n; i++)
			{
				if (w[i] < bind) tempres += (bind - w[i] - 1);
				else if (w[i] > bind) tempres += (w[i] - bind - 1);
			}
			if (tempres < res)
			{
				t = bind;
				res = tempres;
			}
		}
		cout << t << " " << res << endl;
	}


	return 0;
}