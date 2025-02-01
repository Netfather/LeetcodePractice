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

const int N = 45;
int g[N][N];

//定义检查矩阵，
int HengTable[45][37]; //表示第几行的 数字 j 是否出现过 
int ShuTable[45][37]; //表示第几列的 数字 j 是否出现过
int CellTable[6][6][37]; //表示第几个cell里面的  数字是否出现过


int main()
{
	int T;
	cin >> T;
	int i = 0;
	while (i++ < T)
	{
		int n;
		cin >> n;
		memset(HengTable, 0, sizeof HengTable);
		memset(ShuTable, 0, sizeof ShuTable);
		memset(CellTable, 0, sizeof CellTable);
		int len = n * n;
		bool flag = false;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int tmp = 0;
				cin >> tmp;
				g[i][j] = tmp;
				if (tmp > len || tmp <= 0) flag = true;
				if (!flag)
				{
					//一边读入一边做检测
					++HengTable[i][tmp];
					if (HengTable[i][tmp] > 1)
					{
						flag = true;
					}
					++CellTable[i / n][j / n][tmp];
					if (CellTable[i / n][j / n][tmp] > 1)
					{
						flag = true;
					}
					++ShuTable[j][tmp];
					if (ShuTable[j][tmp] > 1) flag = true;
					
				}
			}
		}

		if (flag) cout << "Case #" << i << ": No";
		else cout << "Case #" << i << ": Yes";
		cout << endl;
	}
	return 0;
}