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

// ����ʱ�临�ӶȲ��� ��˿���ʹ�����ر���ѭ��
const int N = 110;
int vi[N];
int wi[N];
int si[N];
int f[N][N];

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i] >> si[i];
	}
	// ��i = 0��ʾ��ѡ�κ���Ʒ ��ʱ�򲻴��ڼ�ֵ ��˱��岻��Ҫ��ʼ��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= v; j++)
		{
			for (int k = 0; k <= si[i]; k++)
			{
				// �������е�i����Ʒ���ܵ�ѡ�� �� 0 һֱ�� si[i] ��
				if (j >= k*vi[i]) f[i][j] = max(f[i][j], f[i - 1][j - k * vi[i]] + k * wi[i]);
			}
		}
	}
	cout << f[n][v] << endl;
	return 0;
}