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

//题干很长  稍微总结一下就是
// 给定一个地图，从起始走到结尾， 有树的地方不能走
// 同时地图上有其他人  每次你移动一次 其他人也可以移动一次   
// 并且其他人会尽可能的来与你走到一个格子上。 求 尽可能少的遇到人的路径

// 这道题可以退化为如下情况  
// 由于你在出森林前一刻的位置是绝对固定的，即 t =0 时刻 你一定在初始位置  t = end 时刻 你必定在出口方格位置
// 那么对于你的挑战者来说，抛开 和你一同移动这个问题，假设 他们在 t = st 时刻 已经到达了出口方格
// 那么 你是无论如何都无法逃脱这次决斗的，  因此 我们只需要计算一下 所有 非零点 距离出口方格的最短距离
// 然后考察一下他们和  你从起始位置移动到最终位置的距离 即可

// 考虑时间复杂度 10的三次方 最坏情况 执行bfs的时间复杂度为 6次方   最坏情况是所有位置都是人 那么此时复杂度为12次方 此时会超时
// 但是我们换个角度思考这个问题  我们从结尾位置出发  找到所有数字点距离结尾位置的最短距离即可 即我们从终点开始搜，搜完全部地图
// 那么只需要bfs一次就可以知道所有的点了
typedef pair<int, int> PII;
int end_x, end_y; //最终出口空地
const int N = 1010;
int dis[N][N]; //记录当前位置到出口空地的距离
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 }; //向量坐标
int r, c; //记录整个棋盘的横纵坐标
char g[N][N]; //记录整个地图

//如下函数初始化dis数组，用于存储所有数字点 到 终点的距离
void bfs_search(int start_x, int start_y)
{
	//重置 dis数组
	dis[start_x][start_y] = 0; //初始位置距离赋值
	queue<PII> q;
	q.push({ start_x,start_y }); //起始位置入队

	while (q.size())
	{
		auto curisor = q.front();
		q.pop();

		int cur_x = curisor.first, cur_y = curisor.second;
		for (int d = 0; d < 4; d++)
		{
			int new_x = cur_x + dx[d];
			int new_y = cur_y + dy[d];
			//当且仅当  新坐标符合规定的时候
			// 新坐标在地图范围内 且 所在地不为树木  且  当前位置没有被走到过
			if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && g[new_x][new_y] != 'T' && dis[new_x][new_y] == -1)
			{
				q.push({ new_x,new_y });
				dis[new_x][new_y] = dis[cur_x][cur_y] + 1;
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	int player_x = 0;
	int player_y = 0; //记录你自己的起始位置
	memset(dis, -1, sizeof dis); //dis数组只需要初始化一次就可以了 
	for (int i = 0; i < r; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++)
		{
			g[i][j] = tmp[j];
			if (tmp[j] == 'S') player_x = i, player_y = j;
			if (tmp[j] == 'E') end_x = i, end_y = j;
		}
	}
	bfs_search(end_x, end_y);
	int dis_level = dis[player_x][player_y];  //记录起点到出口最短要走多少步
	//遍历地图中所有的 非0数字点 通过dis数组 考察他们的距离水平
	int res = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (g[i][j] > '0' && g[i][j] <= '9')
			{
				int dis_judge = dis[i][j];
				if (dis_judge!= -1 &&     dis_judge <= dis_level) res += int(g[i][j] - '0');
			}
		}
	}
	cout << res << endl;
	return 0;
}