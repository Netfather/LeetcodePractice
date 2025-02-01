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

const int N = 1000010;
int p[N]; //��������Ϊ�� ͼ��ÿ����ĵ�ַ���   ������Ϊ��ÿ����ĵ�ַ��Ŷ�Ӧ����һ����ַ���
int num[N]; //��������Ϊ�� ���ڽڵ�ĵ�ַ���  �������Ϊ�� �����ڽڵ����������ͨ���е������ ע������ֻ�����ڽڵ��ѯ����ֵ����ȷ�� �����㶼�Ǵ����

int find(int x)
{
	if (p[x] != x)
	{
		p[x] = find(p[x]);
	}
	return p[x];
}

void connect(int a, int b)
{
	if (a == b) return;  //�Լ����Լ���һ���� û������ ֱ�ӷ���
	int x = find(a);
	int y = find(b);
	p[x] = y; //ab����� ������㽫ab�����ڽڵ��������Ϳ�����
	// ά�����ڽڵ��cnt
	num[y] += num[x];
}

bool query1(int a, int b)
{
	if (a == b)
	{
		return true;
	}
	else if (find(a) != find(b))
	{
		//cout << "No" << endl;
		return false;
	}
	else
	{
		//cout << "Yes" << endl;
		return true;
	}
}

int query2(int a)
{
	return num[find(a)];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		num[i] = 1;
		p[i] = i;
	}
	while (m--)
	{
		string Op;
		int a, b;
		cin >> Op >> a;
		if (Op == "C")
		{
			cin >> b;
			if ( !query1( a,  b)) connect(a, b);
		}
		else if (Op == "Q1")
		{
			cin >> b;
			if (query1(a, b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else
		{
			cout << query2(a) << endl;
		}
	}

	return 0;
}