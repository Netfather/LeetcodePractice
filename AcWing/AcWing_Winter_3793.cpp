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

//非常非常简单的一道题 将数组排序 然后从前往后取 得到对应的分数即可
const int N = 110;
int w[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> w[i];
		sort(w, w + n);

		int res = 0;
		for (int i = 0; i < m; i++)
		{
			if (w[i] < 0) res += abs(w[i]);
			else break;
		}
		cout << res << endl;
	}
	return 0;
}