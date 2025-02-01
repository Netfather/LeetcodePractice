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

// 考虑这样一个 dp格式 
// f[i][j]表示从i,j开始滑的所有路径方案
// 存储格式为 所有路径方案的最大值

//考虑状态转移
// f[i][j]一定能表示为  max(周围4个格子中能滑过去的 所有方案)

// 同时通过反证法可以知道 如果有最大值那么必定是从最高点开始划的
const int N = 310;
int g[N][N];
int f[N][N]; // f[i][j]表示从i,j开始滑的所有路径方案
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int R, C;
int res = -1;

int SearchDp(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];

	//查看一下新点
	int tmp_res = 1;  //自己本身也算所以最起码为1
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C)
		{
			if (g[new_x][new_y] < g[x][y]) tmp_res = max(tmp_res,1 + SearchDp(new_x, new_y));  //当且仅当 新点合法 并且能够滑上去
		}
	}
	f[x][y] = tmp_res;
	return tmp_res;
}



int main()
{
	cin >> R >> C;
	int max_p = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> g[i][j];
		}
	}
		
	memset(f, -1, sizeof f); //初始化所有状态  -1 表示这个点还没有被计算过
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			res = max(res, SearchDp(i, j));
		}
	}
	cout << res << endl; 
	return 0;
}