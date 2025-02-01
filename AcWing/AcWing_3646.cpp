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

//�������� ���ǿ���ȷ�� ������Ҳ��ֻ��7�ַַ�
// ������������500 ��� �������Ҫ�ñ���ö�ٵķ�ʽ�������� 
// ���� 0�ַ� ֻ���ܶ�Ϊ0  7�ַ�ֻ���ܶ� >= 4 
// Ȼ�� 1 6 �ַ�    2 5�ַ�   3 4�ַ� ��ͬʱö�ٵ�
// ���  1 6 �ַ� ���� 7��   2 5�ַ� ���� 7 * 6 ��   3 4 �ַ� ���� 70�� ����ǿ��Թ���

int a, b, c; //�洢���ܹ��ж��ٸ� ƻ���㽶����

//����һ���ܹ������ģ��ж��Ƿ�����
bool check(int x, int y, int z)
{
	return (a >= x) && (b >= y) && (c >= z);
}


//ö�����еı�����
int Table[7][3] =
{
	{0,1,0},
	{1,0,0},
	{0,0,1},
	{0,1,1},
	{1,1,0},
	{1,0,1},
	{1,1,1}
};
int main()
{
	int T;
	cin >> T;
label:
	while (T--)
	{
		int res = -1; //�洢��εĽ��
		cin >> a >> b >> c;
		//�ж� 0 7 
		if (a == 0 && b == 0 && c == 0)
		{
			cout << 0 << endl;
			goto label;
		}
		if (a >= 4 && b >= 4 && c >= 4)
		{
			cout << 7 << endl;
			goto label;
		}
		//�ж� 1 6
		for (int i = 0; i < 7; i++)
		{
			if (check(Table[i][0], Table[i][1], Table[i][2])) res = 1;
			if (check(4 - Table[i][0], 4 - Table[i][1], 4 - Table[i][2]))
			{
				cout << 6 << endl;
				goto label;
			}
		}
		//�ж� 2 5
		for (int i = 0; i < 7; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				if (check(Table[i][0] + Table[j][0], Table[i][1] + Table[j][1], Table[i][2] + Table[j][2])) res = 2;
				if (check(4 - Table[i][0] - Table[j][0], 4 - Table[i][1] - Table[j][1], 4 - Table[i][2] - Table[j][2]))
				{
					cout << 5 << endl;
					goto label;
				}
			}
		}
		//�ж�3 4 
		for (int i = 0; i < 7; i++)
		{
			for (int j = i + 1; j < 7; j++)
			{
				for (int k = j + 1; k < 7; k++)
				{
					int x = Table[i][0] + Table[j][0] + Table[k][0], y = Table[i][1] + Table[j][1] + Table[k][1], z = Table[i][2] + Table[j][2] + Table[k][2];
					if (check(x, y, z)) res = 3;
					if (check(4 - x, 4 - y, 4 - z))
					{
						cout << 4 << endl;
						goto label;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}