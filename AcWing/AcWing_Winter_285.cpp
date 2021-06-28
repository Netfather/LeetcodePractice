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

//����dp���¶�ӵ�����Ƶ���������һ���������ʵ��dp
// ����ά������һ��dp ģʽ  f[u,0] ��ʾ ��uΪ�������ǲ�����u���������뷽��     
// f[u,1] ��ʾ��uΪ�������ǰ���u���������뷽��
// ����״̬ת�ƣ����Ǵ�root��ʼ���ݹ�ļ���������������ķ�����������ά��
// ��� ĳ�����ڵ�ȷ����ѡ���� ��ô���������ӽڵ�һ�������ܱ�ѡ��
// ��� ĳ�������ȷ��ûѡ�� ��ô���������ӽڵ��ѡ �ɲ�ѡ
const int N = 6010;
int e[N], ne[N], h[N], idx;
void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = h[x];
	h[x] = idx++;
}

int w[N]; //�洢����ָ��
int has_father[N];// ���ڱ�ʾĳ��������ĸ������˭  �����ҵ��������root���
int f[N][2]; //���ڴ洢������

int Find(int root,int flag)
{
	if (f[root][0] != -1 && f[root][1] != -1) return max(f[root][0], f[root][1]);
	int res_0 = 0;
	int res_1 = w[root]; //���Ϊ1 ����Ҫ��ָ�����ϵ�ǰ��root

	//����һ�������ٱ�
	for (int i = h[root]; i != -1; i = ne[i])
	{
		int index = e[i];
		int index_0 = Find(index, 0);
		int index_1 = Find(index, 1);
		res_1 += index_0; //�����ǰ���ڵ�ѡ��1  ��ô����������һ������ѡ��
		res_0 += max(index_0, index_1); // �����ǰ���ڵ�ѡ��0 ��ô����������ѡ�ɲ�ѡ
	}
	f[root][0] = res_0;
	f[root][1] = res_1;
	if (flag == 0) return f[root][0];
	else return f[root][1];
}



int main()
{
	memset(h, -1, sizeof h);
	memset(f, -1, sizeof f);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int L, K;
		cin >> L >> K;
		add(K, L);
		has_father[L] = K;
	}
	//Ѱ���������ĸ����
	int root =1;
	while (has_father[root]) root = has_father[root];
	Find(root, 0);
	cout << max(f[root][0], f[root][1]) << endl;
	return 0;
}