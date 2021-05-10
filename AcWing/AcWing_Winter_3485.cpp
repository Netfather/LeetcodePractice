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
// ���������Ҫ��
// ��һ �������������е����� ��� ǰ׺��˼�����ǿ��Խ����鴦���w[n]���飬�ǵ� w[j] ^ w[i-1] = ai^ai+1^ai+2����aj
// �ڶ� Ȼ��ο� ������Ե�˼·�����ǾͿ��Եõ�һ��������������������������
// ���� ����� ���ڴ�Сm������ζ������ÿ������������ǰ�ƶ�һ�� ����Ҫ��trie����ɾ����һ��Ԫ�ء�


//��ΰ� ����������ת��Ϊ �����������ֵĺͣ�
//��ô�ͽ��������a ����Ϊ a0 a0^a1 a0^a1^a2 ������ʽ �ᷢ�������ʽ��ǰ׺����ȫһ�� ����ʵ����ת��
// Ȼ��ʹ��Trie���ķ����������������������ֵ�ҵ� 

// �������Trie���ı���   ������ı��ʾ��� ��ͬ��Ϊ1  ��ͬ��Ϊ0
// ������������� ����ת��Ϊ������ �洢��Trie����
// Ȼ��ÿ��һ���������Ǿ������н���Ѱ��֮ǰ��������֣�����Ѱ��ÿһλ��ȫ��ͬ������

const int N = 100010 * 31; //����һ����100010���֣�ÿ��������32λ ����һ��Ҫ����ô��Ĵ�С
int son[N][2];
int idx = 1; // ��ַ������
int a[N], w[N];
int cnt[N]; //Ϊ��ʵ��ɾ����Trie���е�ĳ����  ��Ҫ����cnt�����ж�

void insert(int x, int v)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //�����ÿһλ �����λ��ʼ
		if (!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
		cnt[p] += v;
	}
	return;
}
// ע�� ���deletee���ֱܴ���ֱ�ӽ�ĳ��λ�ø�0 ��Ϊ���һ�����ֺ����xǰ�����и�λ����ͬ  ����Ϊ����ɾ����ʽ�������
// �� x������ͬ��λ�������޷�������
// void deletee(int x)
// {
// 	int p = 0;
// 	for (int i = 30; i >= 0; i--)
// 	{
// 		int u = x >> i & 1; //�����ÿһλ �����λ��ʼ
// 		p = son[p][u];
// 		son[p][u] = 0; //ɾ��������������
// 	}
// 	return;
// }

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
		if (!cnt[son[p][!u]])
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
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	w[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		w[i] = w[i - 1] ^ a[i];
	}
	int res = INT_MIN;
	//�ȴ����һ��M��С�Ĵ���
	for (int i = 0; i <= m; i++)
	{
		insert(w[i], 1);
		res = max(res, Query(w[i]));
	}
	//�ٴ����������
	for (int i = m + 1, j = 0; i <= n; i++, j++)
	{
		insert(w[j], -1); //�ȴ�trie����ɾ��
		insert(w[i], 1);
		res = max(res, Query(w[i]));
	}
	cout << res << endl;
	return 0;
}