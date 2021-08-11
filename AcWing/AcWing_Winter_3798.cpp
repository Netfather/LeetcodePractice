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

//非常简单的一道题  非零数字 <= 1 为一个幸运年 由于给定的n 必定>=1 意味着 不存在全0的数字，因此 非零数字必定为1
// 又由于给定的是个整数 不存在前导0的问题  所以 给定的整数的第一位 + 1    -   给定的整数 就为所求的幸运年的差值
// 因为  距离最近的下一个幸运年只由最高位的非0数字决定。

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		int temp = 0;
		int i = 9;
		for (; i >= 0; i--)
		{
			temp = n / pow(10, i);
			if (temp) break;
		}
		cout << int((temp + 1) * pow(10, i) - n) << endl;
	}
	return 0;
}