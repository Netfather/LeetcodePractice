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

// ���ݵ�����ʵ�ֵ�˼�� �ֱ�����������
const int N = 100010;
int e[N]; // �洢���в����Ԫ��
int ne[N]; // �洢��ǰ�����ַ ��ָ�����һ����ַ
int pr[N]; //�洢��ǰ�����ַ��ָ���ǰһ����ַ

int idx = 2; //��ַ������  ����������ַ��䵽Ψһ��ַ  0 1��ַ��ͷָ���βָ�����
// �����͵��������Ĳ�ͬ������ �������Ҫ ��ʵ���ڵ�ͷָ�� ����ʵ���ڵ�βָ����
int head = 0; // ͷָ��
int tail = 1;// βָ��

//ʵ�����²���
// ���ʼ�İ汾 ���Ƕ������head Ϊ -1 tailΪ0 ���ַ����Ǽ̳�����һ��ĵ������������˼·�������ǳ�����
// ��Ϊ ����һ������ΪL ���� ��ô����ȫ�޷�����ͷ�ڵ�
// �����ȷ�ķ����� �ֶ�ָ�� 0 1 Ϊͷ βָ��ڵ�  Ȼ���ַ����������Ҫ��2��ʼ
// Ȼ����ô��Ƶĺô����� ������������ֻ�������ֲ��� ���� �� ɾ�� Ȼ���û����


// ʹ��ȫ�¶���� ͷָ�� βָ�� �Ͳ���Ҫ ���� ͷ������ ��Ϊ����ֱ��ʹ��insert K ��ʵ��
//void inserhead(int x)
//{
//	//�����ݲ���
//	e[idx] = x;
//	// ���¿ռ����ԭ����head
//	ne[idx] = head;
//	// ��ԭheadָ���prָ���¿ռ�
//	pr[ne[idx]] = idx;
//	pr[idx] = 0; //prָ����ǰ��ͷ��ַ
//	// ����head
//	head = idx++;
//}
//
//void inserttail(int x)
//{
//	//�����ݲ���
//	e[idx] = x;
//	ne[tail] = idx;
//	pr[idx] = tail;
//
//	ne[idx] = 1; // neָ������β�͵�ַ
//	//ά��tail
//	tail = idx++;
//}

void deletee(int k)
{
	//֮����kҪ+1 �Ĵ������ ����Ϊ��ַ��������2 ��ʼ ���һ����������� ���䵽�ĵ�ַΪ2
	ne[pr[k]] = ne[k];
	pr[ne[k]] = pr[k];
}

void insertRight(int k, int x)
{
	e[idx] = x;

	ne[idx] = ne[k];
	pr[ne[k]] = idx;

	pr[idx] = k;
	ne[k] = idx++;
}

int main()
{
	// ��ʼ��̬
	ne[head] = tail;
	pr[tail] = head;

	int m;
	cin >> m;
	while (m--)
	{
		string Op;
		cin >> Op;
		if (Op == "L")
		{
			int x;
			cin >> x;
			insertRight(head, x);
		}
		else if (Op == "R")
		{
			int x;
			cin >> x;
			insertRight(pr[tail], x);
		}
		else if (Op == "D")
		{
			int k;
			cin >> k;
			deletee(k + 1);
		}
		else if (Op == "IR")
		{
			int k, x;
			cin >> k >> x;
			insertRight(k + 1, x);
		}
		else
		{
			int k, x;
			cin >> k >> x;
			insertRight(pr[k + 1], x);
		}
	}
	for (int i = ne[head]; i != tail; i = ne[i]) cout << e[i] << " ";

	return 0;
}