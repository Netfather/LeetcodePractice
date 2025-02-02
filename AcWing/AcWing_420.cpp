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

//这道题考察的就是给定一串序列，如何得到他的下一个字典序
//具体构造思路为: 
// 1. 从最后一个数往前扫描，如果一直是升序的，说明此时已经不能够被修改了
// 2. 直到扫描到第一个降序的，将那个降序的和左边第一个比他大的数调换位置
// 3. 然后再把后面的完全升序的数组做个reverse 注意C++中reverse是左闭右开的区间
	
const int N = 10010;
int P[N];

void Next_dictionary(int n)
{
	int index_1 = n-1; //用于存储第一个遇到的降序位置
	for (int i = n-1; i >= 1; i--)
	{
		//存储第一个降序位置，然后退出循环
		if (P[i] < P[i + 1])
		{
			index_1 = i;
			break;
		}
	}
	// 然后去寻找比这个位置大的第一个数字
	int index_2 = index_1+1;
	for (; index_2 <= n; index_2++)
	{
		if (P[index_2] < P[index_1])
		{
			swap(P[index_1], P[index_2 - 1]);
			break;
		}
		else
		{
			if (index_2 == n) swap(P[index_1],P[n]);
		}
	}
	reverse(P + index_1 + 1, P + n+1);
	return;
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= m; i++)
	{
		Next_dictionary(n);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << P[i] << " ";
	}
	cout << endl;

	return 0;
}