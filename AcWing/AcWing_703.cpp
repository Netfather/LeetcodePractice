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

const int N = 45;
int g[N][N];

//���������
int HengTable[45][37]; //��ʾ�ڼ��е� ���� j �Ƿ���ֹ� 
int ShuTable[45][37]; //��ʾ�ڼ��е� ���� j �Ƿ���ֹ�
int CellTable[6][6][37]; //��ʾ�ڼ���cell�����  �����Ƿ���ֹ�


int main()
{
	int T;
	cin >> T;
	int i = 0;
	while (i++ < T)
	{
		int n;
		cin >> n;
		memset(HengTable, 0, sizeof HengTable);
		memset(ShuTable, 0, sizeof ShuTable);
		memset(CellTable, 0, sizeof CellTable);
		int len = n * n;
		bool flag = false;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int tmp = 0;
				cin >> tmp;
				g[i][j] = tmp;
				if (tmp > len || tmp <= 0) flag = true;
				if (!flag)
				{
					//һ�߶���һ�������
					++HengTable[i][tmp];
					if (HengTable[i][tmp] > 1)
					{
						flag = true;
					}
					++CellTable[i / n][j / n][tmp];
					if (CellTable[i / n][j / n][tmp] > 1)
					{
						flag = true;
					}
					++ShuTable[j][tmp];
					if (ShuTable[j][tmp] > 1) flag = true;
					
				}
			}
		}

		if (flag) cout << "Case #" << i << ": No";
		else cout << "Case #" << i << ": Yes";
		cout << endl;
	}
	return 0;
}