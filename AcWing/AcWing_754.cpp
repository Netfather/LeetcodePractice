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

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		vector<vector<int>> Table(n, vector<int>(n, 0));

		for (int i = 1; i <= n; i++)
		{
			if (i == 1) //只打印正中间一行的
			{
				int x = 0, y = 0;
				Table[x][y] = i;
				while (++x < n && ++y < n)Table[x][y] = i;
			}
			else
			{
				int x = i - 1, y = 0;
				if (x >= n) break;
				Table[x][y] = i;
				while (++x < n && ++y < n)Table[x][y] = i;
				x = 0, y = i - 1;
				if (y >= n) break;
				Table[x][y] = i;
				while (++x < n && ++y < n)Table[x][y] = i;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << Table[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}