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

//����������Ԫ�ظ�����ͬ ��� �����������Ϊ Ϊÿһ���ҵ�����ȷ��λ��
// �˻�Ϊ   ��֪һ����������У� ��m���ȳ��������� �ҵ�Ԫ���������������Ԫ����ȫһ�µ�����
const int N = 510, M = 250010;
int g[N][N]; //�洢 n�е�m������
int Table[M]; //���ڴ洢��һ�е�Ԫ���Ƿ���ڹ� �Ҵ洢�ڴ���ԭʼ����ĵڼ���
int t[N]; //�洢���е���ȷԪ�ص�����  ������ȷ���� ��ѯ���ֵ


int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int n, m;
	while (T--)
	{
		cin >> n >> m;
		memset(Table, 0, sizeof Table);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int tmp;
				cin >> tmp;
				g[i][j] = tmp;
				if (j == 1) Table[tmp] = i; //ÿһ�еĵ�һ��Ԫ��  ���ڴ��������������һ��
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int tmp;
				cin >> tmp;
				if (Table[tmp])
				{
					t[j] = tmp;
				}
			}
		}
		//������
		for (int i = 1; i <= n; i++)
		{
			int right_rows = Table[t[i]];
			for (int j = 1; j <= m; j++)
			{
				cout << g[right_rows][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}