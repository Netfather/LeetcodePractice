//˼·��
/*
ÿ��������������ͷ��ţ����������  ��ζÿ�����մ��ڵ���3
����Ŀ�������������Ƭ�Բ�ͬλ�õ���ţ��ʼ��������Ϊ�����ǲ�ͬ��
˵�� ��������Ҫ����ö�����еĿ�����
���˼·����
��3��ʼ �ӵ�һ��Ԫ�ؿ�ʼö�����еĿ����ԣ����������ֻ��һͷ��һƷ�ֵ�ţ���������+1

ʹ��ǰ׺��Ȼ��TLE ��Ϊ���ݷ�Χ����

����ÿ��Ǵӽ������  ���������ҵ������з��Ϲ¶�������λ��
Ȼ����Ǹ�λ�ó��� ͳ�����а�����λ�õ� �ܹ���ѡ���������������е���������

*/
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

const int N = 500010;
int s[N];
string cow;
typedef long long LL;
LL res = 0;
LL max(LL a, LL b) {
	return a > b ? a : b;
}
//TLE�汾
//int main()
//{
//	int n;
//	cin >> n >> cow;
//// Ԥ����һ��ǰ׺����
//	s[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (cow[i - 1] == 'H') s[i] = s[i - 1] + 1;
//		else s[i] = s[i - 1] + 0;
//	}
//// ��ʼö��
//	int window = 3;
//	while (window <= n)
//	{
//		for (int i = 1; i <= n - window + 1; i++) if (s[i + window - 1] - s[i-1] == 1 || s[i + window - 1] - s[i-1] == window - 1) res++;
//		window++;
//	}
//	cout << res << endl;
//
//	return 0;
//}

int main()
{
	int n;
	cin >> n >> cow;
	for (int i = 0; i < n; i++)
	{
		LL l = i, r = i;
		LL range_l = 0, rang_r = 0;
		while (l > 0 && cow[--l] != cow[i]) range_l++; // ������� �ҵ���һ���뵱ǰ��һ����λ��
		while (r < n - 1 && cow[++r] != cow[i]) rang_r++; // ���ұ��� �ҵ���һ���뵱ǰ��һ����λ��
		res += range_l * rang_r + max(0, rang_r - 1) + max(0, range_l - 1); // max��Ϊ�˷�ֹ���� rang_l �� rang_rͬʱΪ0�����
		// ͬʱע�⵽  ���п��Ӧ����С��3�� �������� rang_r �� rang_l��Ҫ��1
	}
	cout << res << endl;
	return 0;
}