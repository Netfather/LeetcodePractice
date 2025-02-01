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

// �������յľ�����һ�������к������ж��ǻ������еľ�����˽����󻮷�Ϊ1/4  Ȼ�������1/4����
// �ҵ���Ӧ�������㣬��������ͱ�� ���ʵ��ĸ��������С�ľ����Ƕ��٣� ��Ч�ڻ���ѡַ���⡣
// �ð� ��������˼·�Ǵ����   
// ©������   ����ѡַ������Ч����ƽ����  ��Ϊ�������Сֵ����λ������   ���ź������м�һ��ֵ

//��ȷ���


const int N = 110;
long long g[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> g[i][j];
		//��ʼ�������ϵ�1/4����  ��������� ��ô�м���һ�ж�Ӧ��3������ʵ�������Լ����ǲ���Ҫ�仯��
		long long  res = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = 1; j <= m / 2; j++)
			{
				//�ҵ���Ӧ������������
				int right_up_i = i, right_up_j = m - j + 1;
				int left_down_i = n - i + 1, left_down_j = j;
				int right_down_i = n - i + 1, right_down_j = m - j + 1;
				vector<long long> q;
				q.push_back(g[right_up_i][right_up_j]);
				q.push_back(g[left_down_i][left_down_j]);
				q.push_back(g[right_down_i][right_down_j]);
				q.push_back(g[i][j]);
				sort(q.begin(), q.end());
				for (auto i : q) res += abs(i - q[q.size() / 2]);
				q.clear();
			}
		}
		//����һ���м��Ǹ���
		if (n % 2 && m % 2)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				long long ave = (g[i][m / 2  + 1] + g[n-i+1][m/2 + 1]) / 2;
				res += (abs(ave - g[i][m / 2 + 1]) + abs(ave - g[n - i + 1][m / 2 + 1]));
			}
			for (int j = 1; j <= m / 2; j++)
			{
				long long ave = (g[n/2 + 1][j] + g[n/2 + 1][m-j+1]) / 2;
				res += (abs(ave - g[n / 2 + 1][j]) + abs(ave - g[n / 2 + 1][m - j + 1]));
			}
		}
		else if (n % 2)
		{
			for (int j = 1; j <= m / 2; j++)
			{
				long long ave = (g[n / 2 + 1][j] + g[n / 2 + 1][m - j + 1]) / 2;
				res += (abs(ave - g[n / 2 + 1][j]) + abs(ave - g[n / 2 + 1][m - j + 1]));
			}
		}
		else if (m % 2)
		{
			for (int i = 1; i <= n / 2; i++)
			{
				long long ave = (g[i][m / 2 + 1] + g[n - i + 1][m / 2 + 1]) / 2;
				res += (abs(ave - g[i][m / 2 + 1]) + abs(ave - g[n - i + 1][m / 2 + 1]));
			}
		}
		cout << res << endl;;
	}

	return 0;
}