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

const int N = 1010;
int f[N][N];
int vi[N];
int wi[N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i];
	}

	// ����ѡ�κ���Ʒ��ʱ��  ��Ӧ���ܻ���Ϊ0 ��˲���Ҫ��ʼ��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			// �ȿ��� ��ѡ��i�������
			f[i][j] = max(f[i - 1][j], f[i][j]);
			// �ٿ��� ����ѡ��i��  1�ε����
			if (j >= vi[i])
			{
				f[i][j] = max(f[i][j - vi[i]] + wi[i], f[i][j]);
			}
		}
	}
	cout << f[n][v] << endl;

	return 0;
}