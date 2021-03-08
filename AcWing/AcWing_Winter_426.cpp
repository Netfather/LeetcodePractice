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

const int N = 30010;
const int M = 30;

int dp[M][N]; //dp���壬��1��M����Ʒ��ѡ��ʹ����Ŀ�涨���ֲܷ�����N�����
//���ǽ����⻮�ֳ��������֣��Ƿ�ѡ���i����Ʒ
// �����ѡ���i����Ʒ ��ôǡ����dp[i-1][N]
// ���ѡ���i����Ʒ����ô�ڱ���i����������£��ҵ�1��i-1�� �ܼ�ֵ������N-value[i]�����
// ע������ע�������N��ʾ������Ʒ�ļ۸�Ҳ��������ͳ�Ƶ�����Ʒ�۸񲻳����Ĵ������£�
// ��dp�д洢�����ܷ֣���������һ���������ά�� ��һά��Ϊ��Ʒ�����ڶ�ά��Ϊ��Ʒ�ļ�ֵ��������ȴ����Լ������ά��Ϊ������Ҫ�Ȼ���������˸�������Ʒ��Ȩֵ
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int value, weight;
		cin >> value >> weight; //�����ֵ����Ҫ��Ȩ��
		int sum = value * weight; //�������⣬�ܵļ�ֵ���ܺ�Ϊ�������

		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - value >= 0) dp[i][j] = max(dp[i][j], sum + dp[i - 1][j - value]); // ����������dp��ӵ���sum Ҳ������Ŀ�����Ȩֵ

		}
	}
	cout << dp[m][n];
	return 0;
}