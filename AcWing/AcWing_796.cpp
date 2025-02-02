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

const int N = 1010;
int w[N][N];
int s[N][N]; //二维前缀和数组，表示的是从最左上角的点开始算 一直到自身这个位置的加和  包括自己

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	//读入数据 同时预处理前缀和
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
			s[i][j] = w[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	//处理询问
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}