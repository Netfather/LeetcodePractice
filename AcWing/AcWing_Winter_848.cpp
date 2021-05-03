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

//������˼·���ľ����ڻ��� bfs �Ľṹ  ��� ������������н��
// �������������˼�룬���ǿ���֪��  ���һ������ �������Ϊ0 ˵�� û���κα�ָ���� ��ôҲ��˵��û���κε�����ǰ�棬��ô����һ����������������ǰ��ĵ�

const int N = 1000010;
int e[N], idx, h[N], ne[N];

int rudu[N];   //��¼ĳ�����������Ƕ���  �����洢���ǽڵ��ţ��� ���ǵ�ַ���������ĵ�ַ����
int n, m;
vector<int> res;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool topsort()
{
	//��ʼ����������Ӧ�Ĵ洢����
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (rudu[i] == 0) q.push(i);
	}

	while (q.size())
	{
		int key = q.front();
		res.push_back(key); // ÿ�δӶ����е�����Ԫ�ض������������е���ȷ����
		q.pop();

		// �������ָ������������ߵ���ȼ���
		for (int i = h[key]; i != -1; i = ne[i])
		{
			int index = e[i];
			rudu[index]--;
			if (rudu[index] == 0) q.push(index);
		}

	}
	if (res.size() != n) return false;
	return true;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		rudu[b]++;   // ˵��b�Ŷ���  �����++
	}
	if (topsort())
	{
		for (auto i : res) cout << i << " ";
	}
	else cout << -1;

	return 0;
}