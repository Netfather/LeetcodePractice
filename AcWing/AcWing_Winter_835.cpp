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

// Trie���ĸ������� ��Գ��ֵ���ĸ���٣����ǹ��ɵ��ַ����ܶ࣬�����е��ַ��� �ҵ�һ�����ϣ���ͬ��λ�ù������ַ� ������ͬ��ַ

const int N = 100010;
int son[N][26];  //������洢���ֱ�������Ϊ  �ӵ�i����ַ����һ���ַ�����Ӧ�ַ��ĵ�ַ�������������ھʹ��������ھ���Ծ��ȥ
int idx = 1; //0�ŵ�ַԤ����root Ҳ���ǵ�һ��λ��   �͵����� ˫����һ�� ����ǵ�ַ������ ��Y��д�Ĳ�һ�� ��ΪΪ�˱��� �͵�����ͳһ ��һidxֱ�Ӵ�1��ʼ
int cnt[N]; //���ڱ�־��β

void insert(string a)
{
	int p = 0;
	for (int i = 0; i < a.length(); i++)
	{
		// ����վ��0λ�� Ҳ����root�ڵ� ���󿴵�һ���ַ� �Ƿ���� 
		if (!son[p][a[i] - '0']) son[p][a[i] - '0'] = idx++;// �����ھͷ���һ��
		p = son[p][a[i] - '0']; //��ʱ�����Ƿ���� ���Ƕ��ܹ��ҵ���һ����ַ������ �����帳ֵ����һ�������p
	}
	++cnt[p]; // ѭ�������� p�洢�ľ������һ���ڵ�ĵ�ַ������ֻ��Ҫ����ַ��Ϊ���� cnt��Ӧ������++����
}

int Query(string a)
{
	int p = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (!son[p][a[i] - '0']) return 0;
		p = son[p][a[i] - '0'];
	}
	return cnt[p];
}



int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		char Op;
		string a;
		cin >> Op >> a;
		if (Op == 'I') insert(a);
		else
		{
			cout << Query(a) << endl;;
		}
	}
	return 0;
}