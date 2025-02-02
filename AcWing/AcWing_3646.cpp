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

//根据题意 我们可以确认 最多最多也就只有7种分法
// 而且数据量才500 因此 大概率是要用暴力枚举的方式进行求解的 
// 首先 0分法 只可能都为0  7分法只可能都 >= 4 
// 然后 1 6 分发    2 5分发   3 4分法 是同时枚举的
// 因此  1 6 分法 遍历 7次   2 5分法 遍历 7 * 6 次   3 4 分法 遍历 70次 因此是可以过的

int a, b, c; //存储有总共有多少个 苹果香蕉橘子

//给定一个总共的消耗，判断是否满足
bool check(int x, int y, int z)
{
	return (a >= x) && (b >= y) && (c >= z);
}


//枚举所有的表格可能
int Table[7][3] =
{
	{0,1,0},
	{1,0,0},
	{0,0,1},
	{0,1,1},
	{1,1,0},
	{1,0,1},
	{1,1,1}
};
int main()
{
	int T;
	cin >> T;
label:
	while (T--)
	{
		int res = -1; //存储这次的结果
		cin >> a >> b >> c;
		//判断 0 7 
		if (a == 0 && b == 0 && c == 0)
		{
			cout << 0 << endl;
			goto label;
		}
		if (a >= 4 && b >= 4 && c >= 4)
		{
			cout << 7 << endl;
			goto label;
		}
		//判断 1 6
		for (int i = 0; i < 7; i++)
		{
			if (check(Table[i][0], Table[i][1], Table[i][2])) res = 1;
			if (check(4 - Table[i][0], 4 - Table[i][1], 4 - Table[i][2]))
			{
				cout << 6 << endl;
				goto label;
			}
		}
		//判断 2 5
		for (int i = 0; i < 7; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (check(Table[i][0] + Table[j][0], Table[i][1] + Table[j][1], Table[i][2] + Table[j][2])) res = 2;
				if (check(4 - Table[i][0] - Table[j][0], 4 - Table[i][1] - Table[j][1], 4 - Table[i][2] - Table[j][2]))
				{
					cout << 5 << endl;
					goto label;
				}
			}
		}
		//判断3 4 
		for (int i = 0; i < 7; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				for (int k = j + 1; k < 7; k++)
				{
					int x = Table[i][0] + Table[j][0] + Table[k][0], y = Table[i][1] + Table[j][1] + Table[k][1], z = Table[i][2] + Table[j][2] + Table[k][2];
					if (check(x, y, z)) res = 3;
					if (check(4 - x, 4 - y, 4 - z))
					{
						cout << 4 << endl;
						goto label;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}