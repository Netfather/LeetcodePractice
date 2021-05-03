//思路：

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

const int N = 1000010;
int e[N], h[N], ne[N];
int idx;
int n;
int dis[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int bfs()
{
	//初始化     一般初始化队列 初始化距离 
	queue<int> q;
	q.push(1);
	memset(dis, -1, sizeof dis);
	dis[1] = 0;

	while (q.size())
	{
		int key = q.front();
		q.pop();

		for(int i = h[key] ; i != -1 ;i = ne[i])
		{
			int index = e[i];
			if (dis[index] == -1)   //满足条件的入队 不满足的就直接掠过。
			{
				dis[index] = dis[key] + 1;
				q.push(index);
				if (index == n) return dis[index];
			}
		}
	}
	return -1;
}


int main()
{
	memset(h, -1, sizeof h);
	int m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}

	cout << bfs() << endl;

	return 0;
}