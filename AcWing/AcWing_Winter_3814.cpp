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

// ץס����ĺ��Ĳ���  ���������˻�
// ����� ����������þ����ܶ���� ���1  ����ֻ��ͨ������һ�� ���ұ任��ʱ��һ���ж���һ��仯��
// ��ζ�� һ��ȷ����ĳ����������ô���е��� ����ͬλ���ϵ�����������ͬ���ı任��
// ���  ����������� ��Ȼ�ܱ�֤��Ϊ1 ֻ�п����� �е���ʼ״̬����һ�µġ�
// ���������˻�Ϊ  ����  ����� 01������ �г�ʼ״̬��ȫ����м�����

unordered_map<string, int> Table; //���ڴ洢 ÿ����ͬ���ַ����ĳ��ֵĴ���

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

	//����һ�����еļ�ֵ�� �ҵ����ֵ
	int res = 0;
	for (auto key : Table)
	{
		if (key.second > res) res = key.second;
	}
	cout << res << endl;
	return 0;
}