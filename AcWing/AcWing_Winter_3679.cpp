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

// ����0�����������������ֻ��Ҫ ����ÿһ�� �����2�� �������Ϊ�����ķ�����  ���� 1 �� 4
// Ȼ������������д0    �����Ϳ��Է���  ֻҪÿ�д�λ 1 4 �Ϳ���ʵ����

// �������һ�� 3 4 �Ĵ�С ����ֻ��Ҫ
// 1  4 0 0
// 0  1 4 0
// 0  0 1 4
const int N = 110;
int w[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i++)
		{
			w[i][i + 0] = 1;
			if (i + 1 < n) w[i][i + 1] = 4;
			else w[i][0] = 4;
		}
		//�������
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << w[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}