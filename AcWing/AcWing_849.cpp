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


// dij�㷨�ĺ��ľ����� ά��һ������s  ���s��־�ųɹ�ͬ�������͡� 
// ÿ�ζ��Ӳ���s�ĵ��� ѡ��һ�� ����s����ĵ㣬ͨ�����ǲ���ʽ�Ƚ� ���룬Ȼ���������뵽s ����ά����
// ����� ������ΧΪ500 ������ΧΪ10��5�η�  �ǳ���ͼ ���ʺ�ʹ���ڽӱ���ʽ����Ӧ��ʹ���ٽ������ʽ�洢

const int N = 510;
int g[N][N];
int d[N];   //���ڱ�ʾ   1�ŵ� �� ����С��� ����̾���
bool st[N]; //��ʾ������Ƿ��ѱ�ͬ��
int n, m;

int dijstra()
{
	// ���ȳ�ʼ�� ��1�ŵ����ͬ�� ����Ǿ���
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	//�̶���  dij�㷨һ���Ὣ���е����һ��  ����1�ŵ��Ѿ������� ����ܹ�һ����Ҫ���� n-1��
	for (int i = 0; i < n; i++)
	{
		int t = -1;   //�����ҵ� ����s�� ���Ҿ���1�ŵ��������ĵ�
		for (int j = 1; j <= n; j++)
		{
			if (st[j] == false && (t == -1 || d[j] < d[t])) t = j;
		}
		// �ҵ��� Ȼ��ʼͬ��
		st[t] = true;  //��־����� �Ѿ��������Ѿ����� ׼ȷ�ҵ� ��Сֵ�ĵ��� 
		// Ȼ���������ľ���������һ������������ľ��롣
		for (int j = 1; j <= n; j++)
		{
			// �����µ�ļ��� ��� Ψһ���²���s�е������㷢���仯�����ؾ����ڣ��Ƿ񾭹�t��
			d[j] = min(d[j], d[t] + g[t][j]);
		}
	}
	if (d[n] == 0x3f3f3f3f) return -1;  //�����n����·��Ϊ����󼴲��������·��
	return d[n];
}



int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);    //��ʼ��ͼ ��Ϊ�������·��
								//����ÿ�����ʼΪ���޴�
	while (m--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		//������Ŀ���ܴ����رߺ��Ի�  �����Ҫ�������޳��ᵼ�������������ر�
		g[a][b] = min(g[a][b], w);
	}

	int res = dijstra();

	cout << res << endl;
	return 0;
}