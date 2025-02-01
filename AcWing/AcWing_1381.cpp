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

//此解法由于只保留一位数字，结果是肯定错误的
//因为阶乘的结构未必只受一位数字的影响
//const int N = 1010;
//int dp[N];
////表示第N個階乘的時候，此時最右邊的非零數字是多少
//int GetTarget(int a, int b)
//{
//	//此函數用於返回两个数字相乘后，最右边的非零数字
//	int tmp = a * b;
//	while ((tmp % 10) == 0) 
//	{
//		string temp = to_string(tmp);
//		temp.pop_back();
//		tmp = stoi(temp);
//	}
//	return tmp % 10;
//}


//int main()
//{
//	int n;
//	cin >> n;
//	long long fac = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		fac *= i;
//		while ((fac % 10) == 0)
//		{
//		string temp = to_string(fac);
//		temp.pop_back();
//		fac = stoi(temp);
//		}
//	}
//	cout << fac % 10 << endl;
//	return 0;
//}

//正确解法1
const int N = 1010;
int dp[N];
//表示第N個階乘的時候，此時最右邊的非零數字是多少，保留3位
int GetTarget(int a, int b)
{
	//此函數用於返回两个数字相乘后，最右边的非零数字
	int tmp = a * b;
	while ((tmp % 10) == 0) 
	{
		string temp = to_string(tmp);
		temp.pop_back();
		tmp = stoi(temp);
	}
	return tmp % 1000;
}


int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = GetTarget(dp[i - 1], i);
	}
	cout << dp[n] % 10 << endl;
	return 0;
}


//正确解法2
//const int MOD = 1e9;
//int main()
//{
//	int n;
//	cin >> n;
//	long long fac = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		fac *= i;
//		while ((fac % 10) == 0)
//		{
//			fac /= 10;
//		}
//		fac %= MOD;
//	}
//	cout << fac % 10 << endl;
//	return 0;
//}