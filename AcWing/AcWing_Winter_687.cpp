//思路： 第一个方法 由于问题在于没有保存原来的棋盘，而直接在原有棋盘上修改导致
//形如这种的  9方格都是. 但是是贴着边缘放置的片区没有准确识别  因此必须要设定一个vis数组用于保存这个地方有没有被访问过


//直接使用num来存储周围八个格子有多少雷，然后使用dfs求解才是正确的解法

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <climits>
using namespace std;
const int N = 310;
bool vis[N][N];

int dx[] = {-1,-1,0,1,1,1,0,-1 }, dy[] = { 0,1,1,1,0,-1,-1,-1};


//此法错误，正确解法请看题解
//void dfs(vector<string>& Table, int x, int y, int N)
//{
//	for (int d = 0; d <= 7; d++)
//	{
//		int new_x = x + dx[d], new_y = y + dy[d];
//		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N )
//		{
//			if (Table[new_x][new_y] == '*') return;
//		}
//	}
//	Table[x][y] = '*';
//	for (int i = 0; i <= 7; i++)
//	{
//		int new_x = x + dx[i], new_y = y + dy[i];
//		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && Table[new_x][new_y] != '*')
//		{
//			Table[new_x][new_y] = '*';
//			dfs(Table, new_x, new_y, N);
//		}
//	}
//	return;
//}
//
//
//int main()
//{
//	int test_num = -1;
//	cin >> test_num;
//
//	for (int num = 1; num <= test_num; num++)
//	{
//		cout << "Case #" << num << ":" ;
//		int N = -1;
//		cin >> N;
//		vector<string> Table(N, "");
//		for (int i = 0; i < N; i++)
//		{
//			cin >> Table[i];
//		}
//		int res = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (Table[i][j] == '.')
//				{
//					dfs(Table, i, j, N);
//					if (Table[i][j] == '*') ++res;
//				}
//			}
//		}
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (Table[i][j] == '.') ++res;
//			}
//		}
//		cout << res<<endl;
//	}
//}
