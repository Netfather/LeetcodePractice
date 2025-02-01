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

//״̬ѹ������  + ������ö������
// ��������һ�ֶ�����  ������Ϊ nλ����iλ��0���� ��������i����  ��iλ��1���������i����
// ����f[state][j] ��ʾ state�м�¼�˵�ǰ�Ѿ��߹��˶��ٸ��㣬�������ͣ�ڵ�j��������п���·��������
// ���Դ洢���Ƿ�������Сֵ
// ����״̬ת�ƣ�����state�������Ѿ�Ϊ1��λ��ö�ٳ�����λ�õ�״̬k��Ȼ��f[state_k][u] + w[u][j] Ϊ���ܵĺ�ѡ��
// �����к�ѡ�����min����

const int N = 21, M = 1 << N;
int f[M][N];//dp
int g[N][N]; // �洢���еı�Ȩ

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	//״̬��ʼ��
	memset(f, 0x3f, sizeof f);
	// ״̬Ϊ0��ʾ�����и���û�е� ��ʱ�򲻴��ھ��� Ϊ������
	// ��״̬Ϊ1ʱ ��ʾ������ֻ��0�Ŷ��㣬��ʱ��Ϊ���λ��   �������������λ�� ����������
	f[1][0] = 0; //���λ��û�о��� Ϊ0

	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//ö������״̬  ������Ϊ1��λ�ý��д���
			if (i >> j & 1)
			{
				// f[i][j]
				//1. ���������ǰj����״̬ 
				// ��״̬Ϊ  i - (1 << j)
				//2. �鿴��״̬ ��ЩλΪ1
				for (int k = 0; k < n; k++)
				{
					if ((i - (1 << j)) >> k & 1)
						f[i][j] = min(f[i - (1 << j)][k] + g[k][j], f[i][j]);
				}
			}
		}
	}
	//���Ϊ ��״̬ȫ��Ϊ1 �����ߵ��� n-1�Ŷ˵��ֵ
	cout << f[(1 << n) - 1][n - 1] << endl;

	return 0;
}