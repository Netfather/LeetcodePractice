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

// 由于时间复杂度非常低  只需要简单暴力枚举所有情况就可以了
const int N = 210;
int st[N]; //表示 第 i个人 最喜欢的是第几本书  true为喜欢 false为不喜欢

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int res = 0;
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			if (st[j] == st[i]) res++;
		}
		if (res)	cout << res << endl;
		else cout << "BeiJu" << endl;
	}
	return 0;
}