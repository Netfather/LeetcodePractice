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

// 抓住问题的核心操作  并将问题退化
// 这道题 如果我们想让尽可能多的行 变成1  我们只能通过操作一列 而且变换的时候一整列都是一起变化的
// 意味着 一旦确定了某个方案，那么所有的行 在相同位置上的数都发生了同样的变换。
// 因此  在这种情况下 依然能保证都为1 只有可能是 行的起始状态都是一致的。
// 因此这道题退化为  求问  在这个 01矩阵中 行初始状态完全相等有几个数

unordered_map<string, int> Table; //用于存储 每个不同的字符串的出现的次数

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		Table[str]++;
	}

	//遍历一遍所有的键值对 找到最大值
	int res = 0;
	for (auto key : Table)
	{
		if (key.second > res) res = key.second;
	}
	cout << res << endl;
	return 0;
}