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
int s[N][N]; //��άǰ׺�����飬��ʾ���Ǵ������Ͻǵĵ㿪ʼ�� һֱ���������λ�õļӺ�  �����Լ�

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	//�������� ͬʱԤ����ǰ׺��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
			s[i][j] = w[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	//����ѯ��
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}