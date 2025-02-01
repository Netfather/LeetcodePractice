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

//ǰ׺��˼��  ���� 1 �� -1 ���һֱ�Ǳ��� �����1 ��-1 ��ָ�����ݵ�����  Ȼ��Ԥ����һ��ǰ׺���鼴��
// ͬʱע�⵽ ����  ��������Ե��ܺ�һ���ǹ̶��� ������������⣩ ������������ӱض�����  n * (n-1) / 2 + n
// ���ź��ᳬʱ ������ﻹ��һЩ��ϸ�µ��Ż�����
//const int N = 200010;
//int w[N];
//int s[N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	s[0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i];
//		if (w[i] > 0) s[i] = s[i - 1];
//		else s[i] = (-s[i - 1]);
//	}
//	//��������ѯ��
//	long long res_pos = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			if (s[i] / s[j - 1] > 0) res_pos++;
//		}
//	}
//	cout << n * (n - 1) / 2 + n - res_pos << " " << res_pos << endl;
//	return 0;
//}

// 2O(n)���� ά����������ֱ���  po[N] ne[N] .��ʾ��i��Ԫ�ؽ�β������Ԫ�ضԵĸ���
// ��ô����dp������ ���ǿ���i�õ�һ������ʽ  ÿ�β鿴��������֣����Ϊ�� ����pon = po n-1  + 1 �����1����Ҫ���϶����������Լ�
const int N = 200010;
int w[N];
int po[N];
int ne[N];

int main()
{
	int n;
	cin >> n;
	cin >> w[0];
	//��ʼ��
	if (w[0] > 0) po[0] = 1, ne[0] = 0;
	else po[0] = 0, ne[0] = 1;
	unsigned long long res1 = ne[0], res2 = po[0];

	for (int i = 1; i < n; i++)
	{
		cin >> w[i];
		if (w[i] > 0)
		{
			po[i] = po[i - 1] + 1 , ne[i] = ne[i - 1];
		}
		else
		{
			po[i] = ne[i - 1] , ne[i] = po[i - 1]  + 1;
		}
		res1 += ne[i];
		res2 += po[i];
	}
	cout << res1 << " " << res2 << endl;
	return 0;
}