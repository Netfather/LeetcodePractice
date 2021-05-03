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

const int N = 100010;
int h[N], e[N], ne[N];    //e�洢���� ��Ӧ�ĵ�ı��     hͨ����ı������ ��õ�ַ    ne ��õ�ַ
int idx; //��ַ������
bool status[N];
int n;
int ans = N;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

// ��uΪ���ڵ� ���ĸ��������� ��ͨ�����������ֵ
int dfs(int u)
{
	status[u] = true;  //�Ѿ���������
	int res = 0;
	int sum = 1;    //��1��ʼ����ΪҪ��������
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int index = e[i];
		if (status[index] == false)
		{
			int tmp = dfs(index);  // �õ����Ǹ��ڵ�Ϊ���ڵ�������ͨ������
			res = max(res, tmp);   //�Ƚ�һ��
			sum += tmp;   // �����Լ�
		}
	}
	
	res = max(res, n - sum); // ѡ��u�ڵ�Ϊ���ģ����� ��ͨ��ͼ�ڵ���    �����ԭ������Ϊ��Ҫ������������������ߵ��������ط�����ͨ��
	ans = min(res, ans); //�������ļ��������У���С�������ͨ��ͼ�� �ڵ���
	return sum;
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}