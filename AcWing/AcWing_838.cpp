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

//����һ����������ȫ��������Ȼ�����ֶ������ǰ����б����ʽ�洢�� 
// �������б�洢������������ӵ��һ���ǳ��õ����� ��֪ĳ�����ڵ���±�Ϊu ��ô������ڵ�ض���2u �ҽڵ������ض���2u+1
// ������������������ ����һ�����ڵ� ����ֵ һ�������������ڵ㶼ҪС  �������ݹ�����  ���down up�������� �Ϳ���ʵ�ּ������еĶѲ���
const int N = 100010;
int w[N];
int mysize = 0;

// ��Ҫʵ�� �����ݹ���� down �� up
void down(int u)
{
	int t = u; //�ٶ�����ĵ�ַ������Сֵ  ��Сֵ����u��
	if (2 * u <= mysize && w[2 * u] < w[t]) t = 2 * u;
	if (2 * u + 1 <= mysize && w[2 * u + 1] < w[t]) t = 2 * u + 1;

	if (t != u)
	{
		swap(w[t], w[u]);
		down(t);
	}
	return;
}

void up(int u)
{
	int t = u;
	if (w[u / 2] < w[t]) t = u / 2;

	if (t != u)
	{
		swap(w[t], w[u]);
		up(t);
	}
	return;

}



int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> w[i];
	mysize = n;

	//��ʼ��������
	for (int i = n / 2; i > 0; i--) down(i);

	while (m--)
	{
		cout << w[1] << " ";
		w[1] = w[mysize--];
		down(1);
	}
	return 0;

}
