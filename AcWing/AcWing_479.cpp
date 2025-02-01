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

// ��������������������Լ��Ϊ��ȷ�� ����Ը��ݸ��ڵ����ɹ�������������
//   ����Ĵ��ڣ���֤�˸��ڵ�������������ȫ�����������������
//Ȼ�����ǾͿ����趨��һ��dp״̬ dp[i][j] ��ʾ��i��j������i��j���������ڣ�
//   ������������ķ����Ƕ���
// ͨ����̬�滮�����ǿ��Ժܷ���ĵõ���߷֣���ô��λ����������ǰ�������
// �ٿ�һ��״̬ g[i][j] ������ڼ�¼�����ҵ����ֵ��ʱ�򣬶�Ӧ�ĸ��ڵ���˭

const int N = 35;
int dp[N][N]; //��i��j(����i,j) ��������ڣ����ܹ��ɵ����ж���������߷��Ƕ���
int g[N][N]; //��i��j(����i,j) ��������ڣ����ܹ��ɵ����ж���������߷ֶ�Ӧ�ĸ��ڵ��Ƕ���
int k[N];

void Output(int left, int right)
{
	//�ݹ���ֹ����
	if (left > right) return;
	int root = g[left][right];
	cout << root << " ";
	//�ݹ����������
	Output(left, root - 1);
	Output(root + 1, right);
	return;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> k[i];

	//������� ��ö�ٳ��ȣ�Ȼ��ö����˵�
	for (int len = 1; len <= n; len++)
	{ 
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1; //����õ��Ҷ˵�
			//if (len == 1) dp[i][j] = 1; // ���ĳһ������Ϊ�գ���ô�涨�ӷ�Ϊ1
			if (len == 1) dp[i][j] = k[i], g[i][j] = i; // �������Ϊ1 ��ζ���������ֻ����������ô�������⣬ֻ�����Լ���Ҷ�ӽ��ֻ��Ҫ�����Լ�
			else
			{
				for (int root = i; root <= j; root++) //��ʼö�ٸ��ڵ�
				{
					//�ȼ����i��root-1��������ֵ
					int left;
					if (root == i) left = 1;
					else left = dp[i][root - 1];
					//�ټ����root+1��j��������ֵ
					int right;
					if (root == j) right = 1;
					else right = dp[root + 1][j];
					//���㵱ǰ����ط��ĵ÷��Ƿ��ԭ���Ĵ�����ǣ��͸��½��
					int score = left * right + k[root];
					if (score > dp[i][j])
					{
						dp[i][j] = score;
						g[i][j] = root;
					}
				}
			}
		}
	}

	cout << dp[1][n] << endl;
	Output(1, n);
	cout << endl;

	return 0;
}