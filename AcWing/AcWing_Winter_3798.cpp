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

//�ǳ��򵥵�һ����  �������� <= 1 Ϊһ�������� ���ڸ�����n �ض�>=1 ��ζ�� ������ȫ0�����֣���� �������ֱض�Ϊ1
// �����ڸ������Ǹ����� ������ǰ��0������  ���� �����������ĵ�һλ + 1    -   ���������� ��Ϊ�����������Ĳ�ֵ
// ��Ϊ  �����������һ��������ֻ�����λ�ķ�0���־�����

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