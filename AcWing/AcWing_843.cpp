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

int n;
const int N = 14;
char g[N][N];

bool Zong[N];
bool Zduijiao[2*N];
bool Fuduijiao[2 * N];

// dfsͨɱ�ķ�������  ��һ��д��ֹ���� �ڶ���дһ��ѭ�� ������һ�����еĿ����ԣ� ͬʱ��һ����Ҫ�ں������жϣ�״̬��д���ָ��ֳ�
// ����⻹�и����ĵ���� ��ο����ж��������Ƿ���ͬһ���Խ�����  ʹ�� �ؾ��жϼ���  y= x + c  y = -x + c
void dfs(int depth)
{
	if (depth >= n)
	{
		//˵���Ѿ��ɹ��ҵ���һ���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << g[i][j];
			}
			cout << endl;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!Zong[i] && !Zduijiao[depth + i] && !Fuduijiao[N + depth - i])   //��������û�����֣��Խ�û������ ��ζ������������ʺ�
		{
			g[depth][i] = 'Q';
			Zong[i] = Zduijiao[depth + i] = Fuduijiao[N + depth - i] = true;
			dfs(depth + 1);
			g[depth][i] = '.';
			Zong[i] = Zduijiao[depth + i] = Fuduijiao[N + depth - i] = false;
		}
	}
	return;
}



int main()
{
	cin >> n;
	memset(g, '.', sizeof g);
	dfs(0);


	return 0;
}