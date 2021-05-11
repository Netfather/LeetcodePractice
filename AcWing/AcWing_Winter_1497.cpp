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

// ���ı���  ������Ƿǳ������ �����Ĺ��ڶ����������� ���ʹ�� ����ͺ������ ���ؽ�һ�������� Ȼ�����������µĶ������Ĳ������ 
// �����������µĶ������� ǰ�������
// �������ǿ����þ���ݹ�˼��������   ����һ������  ִ��һ�η��ص�ǰ��������� �� ���������ĸ��ڵ�
// ��������������ص㣬ͨ����������õ����ڵ� ���ǿ����ҵ���������ж�Ӧλ�� ��ôǰһ���������������һ�����������
unordered_map<int,int> inorder_index; //����ָ�����������λ��
const int N = 35;
int l[N];  //�洢�� ĳ���ڵ� �����������ı��
int r[N]; // �洢�� ĳ���ڵ� �����������ı��
int inorder[N], postorder[N];

// l1 l2 ��������������� ��ǰ������������λ��  r1 r2 �����ں��������� ��ǰ����������λ��   //���ص��ǵ�ǰ������ĸ��ڵ�
int Rebuild(int l1, int l2, int r1, int r2)
{
	//�ݹ���ֹ����
	if (l1 > l2 || r1 > r2) return 0;

	int root = postorder[r2];
	int inorder_x = inorder_index[root];
	l[root] = Rebuild(l1, inorder_x - 1, r1, r1 + inorder_x - l1 - 1);
	r[root] = Rebuild(inorder_x + 1, l2, r2 - l2+inorder_x, r2 - 1);
	return root;
}

void bfs(int root)
{
	queue<int> q;
	q.push(root);

	while (q.size())
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
		if (l[tmp]) q.push(l[tmp]);
		if (r[tmp]) q.push(r[tmp]);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> postorder[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> inorder[i];
		//Ԥ����һ�� index
		inorder_index.insert({inorder[i], i});
	}
	int root = Rebuild(1, n, 1, n);
	bfs(root);
	return 0;
}