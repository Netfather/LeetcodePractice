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

// 非常非常经典的 最长上升子序列问题，
// 同时还和最长公共子序列的特别情况 属于 一一对应的关系
const int N = 1010;
int w[N];
int f[N]; //以i为终点的最长上升子序列的长度


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	// 当i为0时候，不存在元素 因此长度为0
	f[0] = 0;
	int res = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1; //至少包括自己
		for (int j = 1; j < i; j++)
		{
			if (w[i] > w[j]) f[i] = max(f[j] + 1, f[i]);
		}
		res = max(res, f[i]);
	}
	cout << res << endl;
	return 0;
}