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

//���鱳������ 
const int N = 110;
int f[N][N];
int vi[N][N]; // ��ʾ��i�� ��j����Ʒ�����
int si[N]; //��ʾ��i����Ʒ�ж��ٸ�
int wi[N][N]; //��ʾ��i�� ��j����Ʒ�ļ�ֵ

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> si[i];
		for (int j = 1; j <= si[i]; j++) cin >> vi[i][j] >> wi[i][j];
	}
	//���Ǳ߽���� ���ӵ�0��ѡ ��ʱ�ļ�ֵ��ȻΪ0 ��˲���Ҫ��ʼ��
	for (int i = 1; i <= n; i++) //�ӵ�i����Ʒѡ
	{
		for (int j = 0; j <= v; j++) // �����������j
		{
			//��ѡ��i����Ʒ�е��κ�һ��
			f[i][j] = max(f[i][j], f[i - 1][j]);
			// ѡ��i����Ʒ �ĵ�k��
			for (int k = 1; k <= si[i]; k++)
			{
				if(j >= vi[i][k]) f[i][j] = max(f[i][j], f[i - 1][j - vi[i][k]] + wi[i][k]);
			}
		}
	}
	cout << f[n][v] << endl;
	return 0;
}