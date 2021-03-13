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

const int N = 210;
char g[N][N];
int dis[N][N]; //标记这个ij这个位置距离起点的距离是多少
int res = -1;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


int bfs(int x, int y, int R, int C)
{
	//起始位置赋值区
	queue<int> cur_x;
	queue<int> cur_y;
	cur_x.push(x);
	cur_y.push(y);
	dis[x][y] = 0;


	//队列判断区
	while (!cur_x.empty())
	{
		int now_x = cur_x.front();
		int now_y = cur_y.front();
		cur_x.pop();
		cur_y.pop();
		for (int d = 0; d < 4; d++)
		{
			int new_x = now_x + dx[d];
			int new_y = now_y + dy[d];
			if (new_x < R && new_x >= 0 && new_y < C && new_y >= 0 && dis[new_x][new_y] == -1 && g[new_x][new_y] != '#')
			{
				dis[new_x][new_y] = dis[now_x][now_y] + 1;
				cur_x.push(new_x);
				cur_y.push(new_y);
				if (g[new_x][new_y] == 'E') return dis[new_x][new_y];
			}
		}
	}
	return -1;
}


int main()
{
	int T;
	cin >> T;
	int i = 0;
	while (i++ < T)
	{
		int R, C;
		cin >> R >> C;
		memset(dis, -1, sizeof dis);
		int start_x = 0, start_y = 0;
		for (int i = 0; i < R; i++)
		{
			string tmp;
			cin >> tmp;
			for (int j = 0; j < C; j++)
			{
				if (tmp[j] == 'S')
				{
					start_x = i;
					start_y = j;
				}
				g[i][j] = tmp[j];
			}
		}
		// 		for (int i = 0; i < R; i++)
		// 		{
		// 			for (int j = 0; j < C; j++)
		// 			{
		// 			    cout <<	g[i][j] << " ";
		// 			}
		// 			cout << endl;
		// 		}
		int res = bfs(start_x, start_y, R, C);
		if (res != -1)cout << res << endl;
		else cout << "oop!" << endl;
	}
	return 0;
}