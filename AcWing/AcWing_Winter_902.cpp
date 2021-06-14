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

//���� dp���� f[i,j]��ʾ ���Ӵ�1��i �䵽1��j ��Ҫ���ٲ��� �洢��ֵΪ  ������������Сֵ
// ���濼��״̬ת�ƣ�  ��� ĩβ������ȣ���ô ֻ��Ҫ���� f[i-1][j-1]����
// ���ĩβ����ȣ���ô ����Ҫ�����Ǵ����ֲ���ת������
// ������һ��Ϊɾ������ �����Ӵ� 1��j ��ô��Ϊ  f[i-1][j] + 1
// ������һ��Ϊ�滻���� ��ô��Ϊ f[i-1][j-1] + 1
// ������һ��Ϊ������� ��ô��Ϊ f[i][j-1] + 1

const int N = 1010;
int f[N][N];

int main()
{
	int n, m;
	string A, B;
	cin >> n >> A >> m >> B;
	//����һ��ͷ
	A = "?" + A;
	B = "?" + B;
	memset(f, 0x3f, sizeof f); //��������Сֵ �����Ҫ��ʼ��Ϊ������

	//��ʼ״̬ ����Ӵ��ӿ�  �䵽��   ��ʱ����Ҫ���� ��Ϊ��� ��˲���Ϊ0
	// ���һ��Ϊ�� ��һ����Ϊ�� ��ô����ɾ�����߲������
	// ��ʼ��
	for (int i = 1; i <= n; i++) f[i][0] = i; //��1��i���Ӵ� ɾ��i�� �ͳ�Ϊ�ռ�
	for (int i = 1; i <= m; i++) f[0][i] = i; //�ӿռ����Ӵ� ����i�� �ͳ�ΪB
	f[0][0] = 0;
	//״̬����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i] == B[j]) f[i][j] = f[i - 1][j - 1];
			else
			{
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}