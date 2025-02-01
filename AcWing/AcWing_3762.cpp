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

//����֤�� ���е�2*2�ľ��� �ض�����ͨ�����·�ʽ����ת��ʹ�� ���������н����Ϊ  0 0 0 0
//  1 1   ==>  0 0    ==> 0 1   ==>  1 1    ==> 0 0
//  1 1		   0 1        1 0        0 1        0 0

// ����������������鷳�ĵط����� ��Ҫ ��������е�Ԫ������ ��� ������ֱ��д�����ұ� ������������������

typedef pair<int, int> PII;
const int N = 30010;
vector<PII> Op[N]; //���ڴ洢ÿ�β���������
int tail = -1; //����ָ��Op�����β������
const int M = 110;
int g[M][M];

//����һ�� 2*2 �Ӿ���� ����λ������ ��1��ʼ����  ��ע���������ά�������ĺϷ��ԡ�
// ��Ȼ��ȫ������ô�鷳 ֻ��Ҫ��¼�ĸ�����û��Ϳ�����
void Operation(int x, int y)
{
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		return;
	}
	// 4��1����� ����
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	// 1��1 ����� ����
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}

	// 2��1 �������ѯ  
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 1;
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Operation(x, y);
	}
	// ����3��1�����
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1 ,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	int n, m;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			string tmp;
			cin >> tmp;
			for (int j = 1; j <= m; j++)
				g[i][j] = tmp[j - 1] - '0';
		}
		tail = -1; //tail����
		for (int i = 1; i < n; i = i + 2)
		{
			for (int j = 1; j < m; j = j + 2)
			{
				Operation(i, j);
			}
		}
		//�����������
		if (n % 2)
		{
			if (m % 2)
			{
				for (int k = 1; k < m; k = k + 2)
				{
					Operation(n - 1, k);
				}
				for (int k = 1; k < n; k = k + 2)
				{
					Operation(k, m - 1);
				}
			}
			else if (m % 2 == 0)
			{
				for (int k = 1; k < m; k = k + 2)
				{
					Operation(n - 1, k);
				}
			}
		}
		else if (n % 2 == 0)
		{
			if (m % 2)
			{
				for (int k = 1; k < n; k = k + 2)
				{
					Operation(k, m - 1);
				}
			}
		}
		//������
		cout << tail + 1 << endl;
		for (int i = 0; i <= tail; i++)
		{
			for (auto element : Op[i])
			{
				cout << element.first << " " << element.second << " ";
			}
			cout << endl;
		}
	}
	return 0;
}