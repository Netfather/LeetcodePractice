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
int w[N];


//���ڲ��鼯������Ҫ�Ĳ�����find���� ��������᷵�ز�ѯ��ĳ����������ڵ㡣 ͬʱ��������ڲ��ҵ�ͬʱ������·���Ͼ����ĵ�ȫ��ָ�����ڽڵ�
int find(int a)
{
	//�����ڳ�ʼ�������У�ÿһ������������w�ж���������һ�����صı�ţ�Ҳ�������Ϊ��ַ ���ʼ  ÿһ���Լ��ĵ�ַָ��Ķ����Լ�����־�Լ������Լ������ڽڵ�
	// ���۲��鼯����޸ģ�ֻ�����ڽڵ�ĵ�ַ���������ֵ  �Ż�����Լ���������ȫ�������������� �������۲�
	if (w[a] != a) w[a] = find(w[a]);  // ���a�ڵ��Լ��������ڽڵ㣬�Ǿ�ȥѰ��aָ����Ǹ��ڵ�����ڽڵ㣬�ҵ�֮�󣬽������ڽڵ㸳ֵ��w[a]
	return w[a];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) w[i] = i; //����ѯ����ֱ�����  ʹ�� ÿһ��1 2 3 �����ĵ�ַ ��Ӧ��ֵΪ1 2 3 ������ 
	// Ҳ����ζ�����ʼ״̬�� n������ȫ����ڵ� Ȼ��ʼ����ָ��
	while (m--)
	{
		char Op;
		int a, b;
		cin >> Op >> a >> b;
		int x = find(a);
		int y = find(b);
		if (Op == 'M')
		{
			w[x] = y; // �޸�x�����ڽڵ� ָ��y
		}
		else
		{
			if (x != y) cout << "No" << endl;
			else cout << "Yes" << endl;
		}

	}
	return 0;
}