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


// �����Ҫת������ ת��Ϊ  ��1��n����Ʒ��ѡ�� �����������n�� ����ѡ���ĸ���
// ��ô�������ޱ�������Ľⷨ˼·  f[i][j]��Ȼ���� ��1��i����Ʒ��ѡ�� �����������j�� ����ѡ���ĸ���
// ��ô����״̬ת�� ��Ϊ�����֣� ��ѡ��i����Ʒ ��ô���� f[i-1][j]��ʾ��ѡ
// ���ȷ��ѡ��i����Ʒ  ��ô����   f[i][j-i] �����֤��������һ��ѡ��
// ��ôѡ�����Ͼ��� �������


// Ψһ��Ҫע��ĵ����״̬�ĳ�ʼ���� ��ѡ��������Ϊ0����ζ��һ����Ʒ����ѡ����Ҳ��һ�ַ���
const int N = 1010;
typedef unsigned long long ULL;
ULL f[N][N];  
const int mod = 1e9 + 7;

int main()
{
	int n;
	cin >> n;

	// ״̬��ʼ��  
	memset(f, 0, sizeof f);
	// 0 �����ڻ��ֿ��� ���
	// ����Ϊ0 ��ʱ�� һ����ѡҲ��һ�ַ���    ����Ӧ��ע�⵽ �漰�� ���ַ��� һ������ѡҲ��һ�ֻ��֡�����
	for (int i = 0; i <= n; i++) f[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j - i >= 0) f[i][j] = f[i][j - i] + f[i - 1][j] % mod;
			else f[i][j] = f[i - 1][j] % mod;
		}
	}
	cout << f[n][n] << endl;

	return 0;
}