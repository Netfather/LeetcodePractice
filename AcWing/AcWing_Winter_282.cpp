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

const int N = 310;
int w[N];
int s[N];
int f[N][N];  //��ʾ���� i�� j �ϲ�Ϊһ���ѵ����кϲ����� ���۵���Сֵ
// ����ת�Ʒ���   �ٶ��м��и�k ��ij���ֳ������֣���  �ܴ���Ϊ  f[i][k] + f[k + 1][j] + s[j] - s[i - 1]

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i], s[i] = s[i - 1] + w[i];
	memset(f, 0x3f, sizeof f);
	// ���Ǳ߽���� ��� f[0]��ʾ����1��0 �ϲ�Ϊһ���ѵĴ��� ��ʱ������ ���Ϊ0
	for (int i = 0; i <= n; i++) f[i][i] = 0;

	// ����ϲ���Ŀ��ģ��ö�٣���ö�ٳ��� ��ö����˵㣬�мǣ�������
	for (int len = 1; len <= n; len++)
	{
		//ö����˵�
		for (int i = 1; i <= n; i++)
		{
			int j = i + len;
			if (j <= n)
			{
				for (int k = i; k < j; k++)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
				}
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}