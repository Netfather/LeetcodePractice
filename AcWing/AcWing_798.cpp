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
int w[N][N];
int b[N][N]; // �洢��־��� ��ij��λ�ñ�ʾ  ��b00 �� bij�ľ��εĺ� = wij


// ��ʱ���Ҫ������ν�һ�����ֲ��뵽��־�������
// ����w�� x1,y1 x2,y2֮�� ���������˵� ������������C��ʱ�� ��� ����ı仯
// ֱ�ӿ��Ǻ��ѿ��ǣ�������վ�ڲ�־���b�ĽǶȣ� �����ԭ����w�ı仯
// ������Ǹ���־���ĳ����+c ��ô��ӳ��ԭ������ ������㿪ʼ�����½�����Ԫ��ȫ��+c
// �����ַ�ʽ���Ժܷ���ı仯��־�����ʹ�� ԭ����ĳ����Χ��Ԫ��+c
void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y2 + 1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
}


int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			insert(i, j, i, j, w[i][j]);
		}
	}

	while (q--)
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  // �򵥵Ķ�ά��ǰ׺�� ��������������ȿ���άǰ׺�͵��ǵ���

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (j == m) printf("%d\n", b[i][j]);
			else printf("%d ", b[i][j]);


	return 0;
}