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

//������ȷ  ���������� �ض�Ϊ����   ����ıض�Ϊż��
// Ȼ��  ż��+ż��  Ϊż��   ����+����Ϊż��  ����+ż��Ϊ����  ����һ��������
// ������������ٶ���ak��ʱ��  ���жϳ���������������ż��   Ȼ��Ѷ�Ӧ��������һ�����
//ʱ�临�Ӷ�Ϊ 10��6�η� ���Թ�
const int N = 100010;
int a[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int b, k;
		cin >> b >> k;
		for (int i = 1; i <= k; i++) cin >> a[i];
		//������ż������� �ж�ÿһ������������ż��
		for (int i = 1; i < k; i++)
		{
			if (b % 2 == 1 && a[i] % 2 == 1) a[i] = 0;
			else a[i] = 1;
		}
		//����һ��β��
		if (a[k] % 2 == 1) a[k] = 0;
		else a[k] = 1;
		// ����ͬ����� �������жϽ������ż����
		int res = a[1];
		for (int i = 2; i <= k; i++) res = !(res ^ a[i]);
		// ����res �� 0 1 ������
		if (res == 0) cout << "odd" << endl;
		else cout << "even " << endl;

	}
	return 0;
}