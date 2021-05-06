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

// Floyd�㷨��������� ��Դ�������Ψһ�ⷨ�����̷ǳ��򵥣����õ�˼��Ҳ��dp��˼��
// ά����һ�� ���� w[i][j][k] ���k��ʾ ������k���� Ҳ���ǵ�ǰ·���ϲ�����k�����ֵ
// ����ʱ�临�ӶȱȽ���⣬����ֻ�����ڳ���ͼ
const int N = 210;
int g[N][N];
int n, m, k;

void floyd()
{
	// ����n������
	for (int k = 1; k <= n; k++)
	{
		// �������
		for (int i = 1; i <= n; i++)
		{
			//�����յ�
			for (int j = 1; j <= n; j++)
			{
				//���Ը���
				if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
			}
		}

	}
}


int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	floyd();
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		if (g[x][y] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
		else cout << g[x][y] << endl;
	}
	return 0;
}