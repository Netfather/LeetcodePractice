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

// dp����Ļ�������1  01 ��������
// ÿ����Ʒֻ��ѡһ��   �� �����������V�������  ����ü�ֵ���
// f[i][j] ��ʾ ��ǰi����Ʒ��ѡ �������������j������ѡ��  �洢������Ϊ ��Щѡ�����ܼ�ֵ�����ֵ
// �������ݣ� ѡ���߲�ѡ��i����Ʒ

const int N = 1010;
int f[N][N];
int vi[N], w[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> w[i];
	}

	//����߽� ���Է��ֱ߽綼��0 ����ر���
	// �ݹ鹹��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			if (j >= vi[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - vi[i]] + w[i]);
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][v]; 
	return 0;
}