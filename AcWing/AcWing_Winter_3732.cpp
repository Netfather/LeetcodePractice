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

//由于数组中元素各不相同 因此 这道题可以理解为 为每一行找到他正确的位置
// 退化为   已知一个乱序的序列， 从m个等长的序列中 找到元素与这个乱序序列元素完全一致的序列
const int N = 510, M = 250010;
int g[N][N]; //存储 n行的m个整数
int Table[M]; //用于存储第一行的元素是否存在过 且存储在错误原始矩阵的第几行
int t[N]; //存储首行的正确元素的排列  给定正确行数 查询这个值


int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int n, m;
	while (T--)
	{
		cin >> n >> m;
		memset(Table, 0, sizeof Table);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int tmp;
				cin >> tmp;
				g[i][j] = tmp;
				if (j == 1) Table[tmp] = i; //每一行的第一个元素  他在错误的排序中在哪一行
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int tmp;
				cin >> tmp;
				if (Table[tmp])
				{
					t[j] = tmp;
				}
			}
		}
		//输出结果
		for (int i = 1; i <= n; i++)
		{
			int right_rows = Table[t[i]];
			for (int j = 1; j <= m; j++)
			{
				cout << g[right_rows][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}