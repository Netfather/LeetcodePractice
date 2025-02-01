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

// bellman-ford�㷨   �ǳ���
//for n��
//for ���б� a, b, w(�ɳڲ���)
//dist[b] = min(dist[b], back[a] + w)
//ʹ��back�ĸ���ԭ������� �㲻������θ��¹��ľ��� ����������� ��ص��µ����֮��ĸ��²�ͬ��
//ע�⣺back[] ��������һ�ε����� dist[] ����ı��ݣ�������ÿ����ͬʱ���������
//�����Ҫ�� dist[] ������б��ݣ��������б��ݻ���˷�������ЧӦ��Ӱ�쵽��һ����

// �μ� ���ǵ�Դ���·�� Ȼ����ڸ�Ȩ��  Ȼ���ǳ���ͼ��ʱ��  �Ϳ���ʹ��bellman-ford�㷨
// ����bellman-ford�㷨��ʱ�临�Ӷȷǳ���� �����㷨 ֻ����������ͼ�Ĺ�ģ�ǳ�С�����
int n, m, k;
const int N = 10010;
int dis[N];

struct Edges
{
	int a;
	int b;
	int w;
}edges[N];


void bellfold()
{
	//��ʼ������
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	int back[N]; //�趨��������

	for (int i = 0; i < k; i++)
	{
		//���ݱ���
		memcpy(back, dis, sizeof dis);
		for (auto key : edges)
		{
			//�������еı� 
			if (dis[key.b] > back[key.a] + key.w)
			{
				//���³ɹ�  ע�� ���µ�λ�� �ڱ��ε�dis ����a��λ�� ֻ��ʹ����һ�ε���ֵ�Ա�֤ͬ��
				dis[key.b] = back[key.a] + key.w;
			}
		}
	}
	//���ڸ�Ȩ�ߵ����� �����޷��ﵽ�ĵ� Ҳ����С��0x3f3f3f3 ��������ṩһ������ֵ
	if (dis[n] >= 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dis[n] << endl;
}

int main()
{
	cin >> n >> m >> k;

	while (m--)
	{
		cin >> edges[m].a >> edges[m].b >> edges[m].w;
	}


	bellfold();
	return 0;
}