//˼·��

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

//�˽ⷨ����ֻ����һλ���֣�����ǿ϶������
//��Ϊ�׳˵Ľṹδ��ֻ��һλ���ֵ�Ӱ��
//const int N = 1010;
//int dp[N];
////��ʾ��N���A�˵ĕr�򣬴˕r����߅�ķ��㔵���Ƕ���
//int GetTarget(int a, int b)
//{
//	//�˺�����춷�������������˺����ұߵķ�������
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

//��ȷ�ⷨ1
const int N = 1010;
int dp[N];
//��ʾ��N���A�˵ĕr�򣬴˕r����߅�ķ��㔵���Ƕ��٣�����3λ
int GetTarget(int a, int b)
{
	//�˺�����춷�������������˺����ұߵķ�������
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


//��ȷ�ⷨ2
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