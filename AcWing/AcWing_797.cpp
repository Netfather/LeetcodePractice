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

const int N = 100010;
int w[N];
int c[N]; // 表示差分数组，表示 从c0 到 ci 包括端点  和的结果等于 w[i]

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) c[i] = w[i] - w[i - 1];  //得到差分数组


	while (m--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		c[l] += k;
		c[r + 1] -= k;

	}
	//还原数组
	for (int i = 1; i <= n; i++)
	{
		c[i] = c[i] + c[i - 1];
		cout << c[i] << " ";  // 从差分数组还原到  原数组
	}
	return 0;
}