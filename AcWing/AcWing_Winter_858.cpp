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

//Prim�㷨��ĳЩ�����Ϻ� ���ذ��dij�㷨�Ƿǳ����Ƶ�  ���ǹ���dis ��ά���ĵ���s���岻ͬ
// ��Prim�㷨��˵  disά�����ǵ�ǰ�㵽����s�е���̾��� �����ǵ���Դ����̾��� ���������Ҳ���� ά���ĵ���s���ַ�Ҳ��һ��
// �����Ƿ������С���������ж� ��ס��ÿ���Ҿ��뼯����С�ıߵ�ʱ�� ��������ҵ�  ��˵������������ˡ�

const int N = 510;
int g[N][N];
int dis[N];
bool st[N];

int n, m;
int res = 0;

bool Prim_MST()
{
	memset(dis, 0x3f, sizeof dis);
	
	for (int i = 1; i <= n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t == -1 || dis[t] > dis[j])) t = j;
		if (i != 1 && dis[t] == 0x3f3f3f3f) return false; //����Ҳ��������ϲ�������ı��� �Ǿ�˵������������С������
		if (i != 1) res += dis[t];
		st[t] = true;
		for (int j = 1; j <= n; j++)
		{
			if ( dis[j] > g[t][j])
			{
				dis[j] = g[t][j];
			}
		}
	}
	
	return true;



}


int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = min(g[x][y], z);
	}
	if (Prim_MST()) cout << res << endl;
	else cout << "impossible" << endl;

	return 0;
}