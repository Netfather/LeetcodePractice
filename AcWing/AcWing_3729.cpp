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


// 类似于区间合并 我们维护一个区间 l r 这个区间表示当前  从l到r的元素都需要置为1
// 什么时候需要区间切换？》 就是新的区间无法和这个区间衔接的时候  就需要更新为新的区间 并把对应区间赋值为1


const int N = 200010;
int w[N];
int res[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(res, 0, sizeof res);
		for (int i = 1; i <= n; i++) cin >> w[i];

		int l = 0, r = 0; //维护区间
		for (int i = 1; i <= n; i++)
		{
			int tmp_l = 0, tmp_r = 0;
			if (w[i])
			{
				if (w[i] >= i) tmp_l = 1, tmp_r = i;
				else tmp_l = i - w[i] + 1, tmp_r = i;

				//检查本次区间是否和上次区间有交集
				if (tmp_l <= r) l = min(l, tmp_l), r = max(l, tmp_r);
				else
				{
					for (int j = l; j <= r; j++) res[j] = 1;
					l = tmp_l;
					r = tmp_r;
				}
			}
		}
		for (int j = l; j <= r; j++) res[j] = 1;
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}