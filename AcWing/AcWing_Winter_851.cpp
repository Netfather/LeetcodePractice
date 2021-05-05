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

//spfa �� ��i�Ż���dij�ǳ������� �����μ����¼��㲻ͬ
// ���Ƶ�ά�� spfa��st��Ϊ�˱���һ�����Ƿ��Ѿ��ڶ�����   dij��st�Ǳ�����ǰ������Ƿ��Ѿ�ͬ�� ͬ�����Ĳ���Ҫ�ٴο���
// ���е����� spfa�Ķ��о�����ͨ�Ķ��У� dij�Ķ��������ȶ��� ��ͨ��������µ�


//spfa������ bell-ford�㷨���Ż�  ���� bellman�㷨 ��ʵ�������еı���һ��û�б�Ҫ�Ĳ�������Ϊ��Щ�ߺ�Դ���ǲ���ͨ�ģ�
//��˴ӱ�����˵ ��Щ������ȫ���ø��µ�  ���ǵ����۲죬spfa�㷨��bfs��˼����������
// ������ dij�㷨�Ķ��Ż��汾��ʹ��һ��������ά��֮ǰ���¹���ǰ���ڵ㣬Ȼ��ʹ�ø��¹��ĵ����������ڵĵ�

// ����Ż��汾��dij�㷨��� ���spfa����������    ���е�һ��������Ϊ��Ҫ  dij�ĵ���s��ֻ��ά��һ�ε� ֻҪ������� ����Զ�޷��Ƴ�
//1] Dijkstra�㷨�е�st���鱣����ǵ�ǰȷ���˵�Դ�������С�ĵ㣬��һ��ȷ������С��ô�Ͳ�������(���ɱ��Ϊtrue��ı�Ϊfalse)��
//SPFA�㷨�е�st�������ֻ�Ǳ�ʾ�ĵ�ǰ���������µĵ㣬��spfa�е�st�������(�����ڱ��Ϊtrue֮���ֱ��Ϊfalse)��
//˳��һ�����BFS�е�st�����¼���ǵ�ǰ�Ѿ����������ĵ㡣
//2] Dijkstra�㷨��ʹ�õ������ȶ��б�����ǵ�ǰδȷ����С����ĵ㣬Ŀ���ǿ��ٵ�ȡ����ǰ��Դ�������С�ĵ㣻
//SPFA�㷨��ʹ�õ��Ƕ���(��Ҳ����ʹ�ñ�����ݽṹ), Ŀ��ֻ�Ǽ�¼һ�µ�ǰ���������µĵ㡣

// �������spfa�㷨 ��һ��������ȱ������ ����������ָ�Ȩ��·����Ϊһ�����ָ�Ȩ��· ͬ����ʹѭ��������ѭ��

//����������ϡ��ͼ ��˲��ʺ�ʹ��bellman�㷨����
const int N = 1000010;
int e[N], ne[N], w[N], h[N];
int idx; //��ַ������

void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

int n, m;
int dis[N];
int st[N]; //���st �� dij�еĵ���s���ű��ʵ�����   �����st��Ϊ�˱���������Ƿ��Ѿ��ڶ�������
typedef pair<int, int> PII;

int spfa()
{
	//��ʼ������ 
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;

	//��ʼ������  ע�����ﲻ�����ȶ��� ���Ƕ��ж���
	queue<int> q;
	q.push(1); //1�Ŷ˵�ľ���Ϊ0

	//ע����һ���ͺ�heap_dij��������������  ��heap���� �����ǲ���Ҫ�ֶ������ ���е�ȫ���ں��� ����Ϊn�ε�ѭ����
	st[1] = true; // ���ڱ�ʾ 1�õ��Ѿ������


	while (q.size())
	{
		auto key = q.front();
		q.pop();
		
		int key_index = key;
		//��ʱ�����Ӷ������ó� ���һ��
		st[key_index] = false;

		//�������к����������ĵ�
		for (int i = h[key_index]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//���Ը���
			if (dis[index] > dis[key_index] + weight)
			{
				//ֻҪ�����仯 ��һ��Ҫ����
				dis[index] = dis[key_index] + weight; 
				//���³ɹ�  ��������㲻�ڶ�����  ��heap�����ȶ��е�������ͨ��st�����д���� 
				// ��spfa�㷨�� ��������Ǹ���st������ģ����һ�����Ѿ��ڶ����� ���º����Ľ����С �������ڱ��θ���
				if (!st[index])
				{
					q.push( index );
					st[index] = true;
				}
			}
		}
	}
	if (dis[n] == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << dis[n] << endl;
	return 0;
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
	spfa();

	return 0;
}