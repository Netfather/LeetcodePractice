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


// ������������͵������ܴ�������  ����Ҫʹ�����ȶ��������� 
// ��Ϊ����dij�㷨�� ����������������ڣ� ÿ���ҵ� ����s�е�  ��������ĵ� ���ĵ�ʱ��ʵ����̫����
// ������￼��ʹ�����ȶ��еķ�ʽ�� ����ά�����ȶ��У�ÿ�������˾��� ���ǾͰ��Ǹ���Ӧ�ĵ�;�����ӣ�Ȼ����м���

//������ϡ��ͼ ����ʹ���ڽӱ�洢
const int N = 1000010;
int e[N], h[N], w[N], ne[N], idx;
int d[N];
bool st[N]; //���ڱ�ʾ������Ƿ��Ѿ��ڵ���s����
typedef pair<int, int> PII;
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}


int heap_dijstra()
{
	//������������
	memset(d, 0x3f, sizeof d);
	d[1] = 0; // 1�Ŷ���ľ���Ϊ0

	//����С����
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 }); //���ڱ���Ҫ�þ�����ǰ �ſ��Ը��ݾ������ж�  ��ΪС����Ĭ������ ��Ԫ����Ϊ��������

	while (heap.size())
	{
		auto k = heap.top();
		heap.pop();
		int ver = k.second;  // ����ֻ��Ҫ�ó�����Ϳ�����   dis �Ѿ����Ը��� d[ver] ����������
		// 	����Ҫ��һ��������С���ѻ�������౸�ݣ�������������Ԫ���Ѿ���s���� ���Ǿ�ֱ������
		if (st[ver]) continue;
		st[ver] = true;

		//����������һ������ͨ�����е�
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//�������ֱ��ʾ ���ver�����ӵ�  ��Ȩ�Ͷ�Ӧ�Ķ�����
			//Ȼ���Ը���
			if (d[index] > d[ver] + weight)
			{
				//˵�����Ը���
				d[index] = d[ver] + weight;
				heap.push({ d[index],index });
			}
		}
	}
	if (d[n] == 0x3f3f3f3f) return -1;
	return d[n];
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int t = heap_dijstra();

	cout << t << endl;

	return 0;
}