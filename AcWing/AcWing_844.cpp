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

// 经典bfs方法找迷宫最短路径问题 所有的bfs方法 基本都需要个dis数组来反应从起点走到当前点使用了多少步
typedef pair<int, int> PII;
const int N = 110;
int n;
int m;

int g[N][N];
int dis[N][N];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int bfs(int start_x, int start_y)
{
	queue<PII> q;
	//队列初始化
	q.push({ start_x,start_y });
	dis[start_x][start_y] = 1;

	while (q.size())
	{
		auto k = q.front();
		q.pop();
		int x = k.first;
		int y = k.second;

		for (int i = 0; i < 4; i++)
		{
			//得到准备走的下一个点的坐标
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			//但是这个坐标必须满足条件
			if (new_x < n && new_x >= 0 && new_y >= 0 && new_y < m && !dis[new_x][new_y] && g[new_x][new_y] == 0)
			{
				q.push({ new_x,new_y });
				dis[new_x][new_y] = dis[x][y] + 1;
				if (new_x == n-1 && new_y == m -1) return  dis[new_x][new_y];
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
	}

	int res = bfs(0, 0);

	cout << res - 1;
	return 0;
}