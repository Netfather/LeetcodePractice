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

//ͬ�� �������ذ�dij�㷨���Ż�������ͬ������ָ������Ż�Prim�㷨  
// Kruskal�㷨��ʱ�临�Ӷ��Ϸǳ������ƣ���������㷨��ĳ�̶ֳ�����̰�ĺͲ��鼯����ĺϲ�
// ���ǽ����еı߱�����������һ������Ȼ��������еı�Ȩ����������Ȩ���ӵ�������û����ͨ ��ֱ�Ӽ�����С����������

const int N = 200010;
struct Edges
{
	int w;
	int a;
	int b;

	 bool operator< (const Edges& tmp) const
	{
		return w < tmp.w;
	}
}edges[N];
int p[N]; //���鼯ʹ�� ���ڲ�ѯ��ŵ����ڽڵ�
int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int n, m;
int main()
{
	int res = 0;
	int cnt = 1;
	cin >> n >> m;
	//��ʼ�����е����ڽڵ�
	for (int i = 1; i <= n; i++) p[i] = i;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = { z,x,y };
	}
	sort(edges, edges + m);
	for (int i = 0; i < m; i++)
	{
		auto key = edges[i];
		int x = find(key.a);
		int y = find(key.b);
		if (x != y)
		{
			++cnt;
			res += key.w;
			p[x] = y;
		}
	}
	if (cnt < n) cout << "impossible" << endl;
	else cout << res;
	return 0;
}