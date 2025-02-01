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

//1. 解释一下mex是什么意思， 就是一个集合，从0，1，2一直到无穷大，第一个没有的数字 就是这个集合的mex值
//2. 考虑到子集的特性，如果我们要 mexA+mexB尽可能大，那么就意味着，这个集合的第一个不是两份的数字，必定会是结果中的第一个
//3. 因为任何一个数字要么是A 要么是B，如果不是两份，意味着这个数字必定会在一个集合中断档，
//4. 然后再考察从该点之后，第一个断点的数字即可

//5. 基于以上观察，直接统计一个数字出现频率表格会非常简单
const int N = 110;
int w[N];
int Table[N]; //统计某个数字是否出现过


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(w, 0, sizeof w);
		memset(Table, 0, sizeof Table);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			++Table[w[i]];
		}
		int res = 0;
		int flag = 0;
		for (int i = 0; i <= 100; i++)
		{
			//1.找到第一个数字小于2的点
			if (flag == 0 && Table[i] < 2) res += i,flag = 1;
			//2.找到在这之后的第一个断点 也就是找不到的点
			if (flag == 1 && Table[i] == 0)
			{
				res += i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}