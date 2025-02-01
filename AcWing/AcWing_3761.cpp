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

const int N = 200010;
int w[N];
int Table[N]; //用于存储  数字对应的编号
// 编码格式   索引为 w[i] 对应的数字为i 表示 这个数字对应的索引
// 如果同一个数字出现了2次 那么就把索引修改为-1

int main()
{
	ios::sync_with_stdio(false);


	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(Table, 0, sizeof Table); //清空一下查找表Table
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			if (Table[w[i]] == 0) Table[w[i]] = i;  // 数字出现第一次  Table存储这个数字对应的下标
			else if (Table[w[i]] != 0) Table[w[i]] = -1; //数字出现超过一次  Table存储 -1 表示这个数字已经不符合要求
		}
		int res = INT_MAX;
		int res_index = -1; // 如果如下的循环无法改变index的值 那么为直接输出-1
		// 再次遍历一遍所有的数  找到 Table不为0 也不为-1 的可以更新的点 
		for (int i = 1; i <= n; i++)
		{
			if (Table[w[i]] != 0 && Table[w[i]] != -1)
			{
				if (w[i] < res)
				{
					res_index = i;
					res = w[i];
				}
			}
		}
		cout << res_index << endl;
	}


	return 0;
}
