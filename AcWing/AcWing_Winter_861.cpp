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


////�������㷨  ���ж���ͼ�����ƥ��  ��Ŀ�Ǹ���һ������ͼ���������ҵ�ʹ�ö���ͼ�ܹ�����޶ȵ�����������ͬ�Ĳ��ֵ�һ�����
// ����㷨 ���¾��� ����һ��find���� �����������Ϊ�����Ķ��� ����һ�� ����
// �����������Ҫ���ٵ��ҵ� ĳ�������Ӧ���ٱ�����Щ ������ﻹ����Ҫʹ���ڽӱ����洢��Ӧ����Ϣ
const int M = 100010;
const int N = 510;
int e[M], ne[M], h[N], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int n1, n2, m;
int match[N]; //���ڱ��� ĳ������ ��Ӧ����һ�����Ƕ���
// һ��Ҫ��һ�� st ���ڱ��� �ڱ���ģ���� �����Ƿ��Ѿ��������� ��������� �Ͳ��ٽ��еݹ� �����������ѭ��
int res = 0;

bool find(int x)
{
	//����һ��x�������ٱ�
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int index = e[i];
		//�����Ӧ�Ķ���û��ƥ�� ���� �����Ӧ�Ķ����Ѿ���ƥ������� ���Ǿ�Ŭ������ȥ�ö���Ķ���ȥ����Ѱ��һ������
		if (!match[index] || find(match[index]))
		{
			match[index] = x;
			return true;
		}

	}
	//���������а취 ������ƥ���� �ͷ���false
	return false;
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n1 >> n2 >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
	}
	for (int i = 1; i <= n1; i++)
	{
		memset(match, 0, sizeof match);
		//�������ߵ����ж��� , ����ܷ��䵽��� �ͽ�res++ 
		if (find(i)) res++;
	}
	cout << res << endl;
	return 0;
}

//�������㷨  ���ж���ͼ�����ƥ��  ��Ŀ�Ǹ���һ������ͼ���������ҵ�ʹ�ö���ͼ�ܹ�����޶ȵ�����������ͬ�Ĳ��ֵ�һ�����
// ����㷨 ���¾��� ����һ��find���� �����������Ϊ�����Ķ��� ����һ�� ����
// �����������Ҫ���ٵ��ҵ� ĳ�������Ӧ���ٱ�����Щ ������ﻹ����Ҫʹ���ڽӱ����洢��Ӧ����Ϣ
//const int M = 100010;
//const int N = 510;
//int e[M], ne[M], h[N], idx;
//void add(int a, int b)
//{
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//int n1, n2, m;
//int match[N]; //���ڱ��� ĳ������ ��Ӧ����һ�����Ƕ���
//bool st[N]; //���ڱ�ʾn2�㼯���Ƿ��Ѿ���ƥ��
//int res = 0;
//
//bool find(int x)
//{
//	//����һ��x�������ٱ�
//	for (int i = h[x]; i != -1; i = ne[i])
//	{
//		int index = e[i];
//		if (!st[index])
//		{
//			//�����Ӧ�Ķ���ǡ��û�б�ƥ�� ���Ǿ�ֱ��ƥ���������
//			st[index] = true;
//			// ����������û��match ������match�Ķ����ܹ�������� ��ô���Ǿͽ����xд��match��
//			if (!match[index] || find(match[index]))
//			{
//				match[index] = x;
//				return true;
//			}
//		}
//	}
//	//���������а취 ������ƥ���� �ͷ���false
//	return false;
//}
//
//
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n1 >> n2 >> m;
//	while (m--)
//	{
//		int x, y;
//		cin >> x >> y;
//		add(x, y);
//	}
//	for (int i = 1; i <= n1; i++)
//	{
//		memset(st, false, sizeof st);  //ÿ��ģ��֮ǰ ͳһ��st�������
//		//�������ߵ����ж��� , ����ܷ��䵽��� �ͽ�res++ 
//		if (find(i)) res++;
//	}
//	cout << res << endl;
//	return 0;
//}