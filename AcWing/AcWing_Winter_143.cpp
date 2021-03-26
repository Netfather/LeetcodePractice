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

//�������Trie���ı���   ������ı��ʾ��� ��ͬ��Ϊ1  ��ͬ��Ϊ0
// ������������� ���ǰ���תΪһ��string���� ������ �洢��Trie����
// Ȼ��ÿ��һ���������Ǿ������н���Ѱ��֮ǰ��������֣�����Ѱ��ÿһλ��ȫ��ͬ������

const int N = 100010 * 31; //����һ����100010���֣�ÿ��������32λ ����һ��Ҫ����ô��Ĵ�С
int son[N][2];
//int cnt[N]; //ע�⵽��������ȫÿһλ������32λ���������ǲ���Ҫʹ��cnt�������洢����λ�� 
int idx = 1; // ��ַ������
void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //�����ÿһλ �����λ��ʼ
		if (!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
	}
	return;
}
//Query�����������������в��ң��ҵ�����ƥ���� �����ֵ
int Query(int x)
{
	int p = 0;
	int res = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //����ÿһλ�������λ��ʼ 
		//����ÿ�ξ����߲�ͬ��λ��

		//���ź� ��ͬλ�õ��ӽڵ㲻����
		if (!son[p][!u])
		{
			p = son[p][u];
			res = res * 2 + u;
		}
		else
		{
			p = son[p][!u];
			res = res * 2 + !u;
		}
	}
	//�ҵ�Ŀǰ�洢������������ ���ŵĽ��res
	return res ^ x; //���������


}

int main()
{
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		insert(tmp);
		res = max(res, Query(tmp));
	}
	cout << res;


	return 0;
}