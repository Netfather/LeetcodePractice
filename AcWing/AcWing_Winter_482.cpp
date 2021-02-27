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

//��������Ӧ��ע�⵽������������⣬��ؼ��ĵ�����м���ߵ�ͬѧ
//����֪�м����ͬѧ�Ļ����ϣ�����ֻ��Ҫ����������У�һ�������������һ������½�����
//������������֪�м����ͬѧ�Ļ����ϣ���������������ȫ�����ģ���˴�ʱ�Ϳ��Ժ��������������Ҫ���м���ͬѧ

const int N = 110;
int height[N];
int dp_up[N]; //���״̬�����ʾ����1��i�м䣬���������ĳ���
int dp_down[N];//���״̬�����ʾ����i��N��������½�����ĳ���

void Solv_up(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dp_up[i] = 1; //���� �Լ�����һ����һ����������
		//Ȼ�� �������Լ���ͳ�ƴ�ͷ��ʼ�����еı��Լ�С����
		for (int j = 1; j < i; j++)
		{
			//����������ϸ��С�ڣ��������Ҳ��Ҫ�ϸ�С��
			if (height[j] < height[i])
			{
				dp_up[i] = max(dp_up[i], dp_up[j] + 1);
			}
		}
	}
	return;
}

void Solv_down(int n)
{
	for (int i = n; i >= 1; i--)
	{
		dp_down[i] = 1;
		// ͳ�����д�����β����ʼ�����еı��Լ�С������
		for (int j = n; j > i; j--)
		{
			if (height[j] < height[i])
			{
				dp_down[i] = max(dp_down[i], dp_down[j] + 1);
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
	}
	Solv_up(n);
	Solv_down(n);

	//Ȼ�����ͳ��
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(dp_up[i] + dp_down[i], res);
	}
	cout << n - res + 1 << endl;
	return 0;
}