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

// SPFA�㷨�жϸ���  �������ص�spfa�㷨�����ڴ���ϡ��ͼ����� ͼ�в����ڸ�������ľ����ⷨ�� ��������Ͷ��Ż�dij�㷨����
// �������ű��ʵĲ�ͬ ʹ��һ������ ��������һ�θ��¹����з����仯��ֵ  Ȼ�󲻶����� ֱ�����ն���Ϊ��Ϊֹ
// ������ڸ��� ��ô������н���һֱ���� ������ѭ��  ��ô���ʹ��spfa���жϸ�����

// ���ݳ���ԭ�����ǿ���֪�� ���һ��������·�� ������ n���� ��ô��ζ��·���ϱض���һ���ط��Ķ��������ظ��� Ҳ����ζ�Ŵ��ڸ���
// ������ϡ��ͼ ���ʹ���ڽӱ�洢
const int N = 10010;
int e[N], w[N], ne[N], h[N], idx;
void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

int n, m;
int cnt[N]; // ���ڱ��Ŀǰ���·�����˶��ٸ�����
int dis[N];
bool st[N];

bool spfa_neg() //����Ϊ������
{
	//��һ����ʼ������
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;  //��һ����Ϊ���ṩ�ʼ����  ȷ�������ܹ���ȷ������ȥ��
	// �ڶ�����ʼ������
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}
	// ���ڸ�������һ����1�ŵ㿪ʼ ���������Ҫ�������еĶ��� ���һ����һ������� �ᳬʱ  ���ֻ��Ҫ�Ѷ���ȫ����������м���


	while (q.size())
	{
		auto key = q.front();
		q.pop();
		st[key] = false;

		//�����������������ٱ�
		for (int i = h[key]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//���Ը���
			if (dis[index] > dis[key] + weight)
			{
				dis[index] = dis[key] + weight;
				cnt[index] += 1; //˵��������һ����  cnt����++
				if (cnt[index] >= n) //˵�����ڸ�Ȩ
				{
					return true;
				}
				if (!st[index])
				{//�������㲻�ڶ����� ����벢���ñ�־λ
					q.push(index);
					st[index] = true;
				}
			}
		}
	}
	return false;
}



int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}


	if (spfa_neg())
	{
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}