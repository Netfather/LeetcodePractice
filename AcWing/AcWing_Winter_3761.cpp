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

const int N = 200010;
int w[N];
int Table[N]; //���ڴ洢  ���ֶ�Ӧ�ı��
// �����ʽ   ����Ϊ w[i] ��Ӧ������Ϊi ��ʾ ������ֶ�Ӧ������
// ���ͬһ�����ֳ�����2�� ��ô�Ͱ������޸�Ϊ-1

int main()
{
	ios::sync_with_stdio(false);


	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(Table, 0, sizeof Table); //���һ�²��ұ�Table
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			if (Table[w[i]] == 0) Table[w[i]] = i;  // ���ֳ��ֵ�һ��  Table�洢������ֶ�Ӧ���±�
			else if (Table[w[i]] != 0) Table[w[i]] = -1; //���ֳ��ֳ���һ��  Table�洢 -1 ��ʾ��������Ѿ�������Ҫ��
		}
		int res = INT_MAX;
		int res_index = -1; // ������µ�ѭ���޷��ı�index��ֵ ��ôΪֱ�����-1
		// �ٴα���һ�����е���  �ҵ� Table��Ϊ0 Ҳ��Ϊ-1 �Ŀ��Ը��µĵ� 
		for (int i = 1; i <= n; i++)
		{
			if (Table[w[i]] != 0 && Table[w[i]] != -1)
			{
				if (w[i] < res)
				{
					res_index = i;
					res = w[i];
				}
			}
		}
		cout << res_index << endl;
	}


	return 0;
}
