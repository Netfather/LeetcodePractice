//思路： 使用flood fill算法  加上 dfs 和  bfs 的通用模板，具体模板参看OneDrive中的配图，是一种解决flood fill问题非常好用的一种方法

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
#include <climits>
using namespace std;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };



//結果正確 但是一开始超时了，问题的关键在于一开始没有处理好 bfs的边界条件判定，导致多重复走了很多次
// 核心要点： 对于bfs 一般我们通过队列可以构建一个模板，然后我们必须保证每一次只搜自己，然后剩下的未处理的，我们入队，来进行后续的处理
// 一般我们在修改判定条件的时候，在入队的时候，就修改，然后出队的元素，我们可以不进行if判定，就直接进行++操作
//int bfs(vector<vector<char>> &Blocks, int start_x, int start_y, int width, int height)
//{
//
//	queue<int> q_x;
//	queue<int> q_y;
//
//	int cnt = 0;
//	q_x.push(start_x);
//	q_y.push(start_y);
//
//	while (!q_x.empty())
//	{
//		
//		int now_x = q_x.front();
//		int now_y = q_y.front();
//		q_x.pop();
//		q_y.pop();
//
//		cnt++; //由于在入队的时候就已经表示访问过了，因此出队的时候我们一般不需要进行判定，直接结果++就可以
//		//if (Blocks[now_x][now_y] == '.')
//		//{
//		//	Blocks[now_x][now_y] = '#';
//		//	cnt++;
//		//}
//
//		for (int d = 0; d < 4; d++)
//		{
//			int a = now_x + dx[d], b = now_y + dy[d];
//			if (a >= 0 && a < height && b >= 0 && b < width && Blocks[a][b] == '.')
//			{
//				Blocks[a][b] = '#';  //在这里修改标志位，表示这个地方已经访问过了
//				q_x.push(a);
//				q_y.push(b);
//			}
//		}
//	}
//	return;
//}
//
//
//int main()
//{
//	while (true)
//	{
//		int cnt = 0;
//		int width = -1, height = -1;
//		cin >> width >> height;
//		if (width == 0) break;
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '#';
//				}
//			}
//		}
//		int res = bfs(Blocks, start_x, start_y, width, height);
//		cout << res << endl;
//	}
//	return 0;
//}



#define x first
#define y second
typedef pair<int, int> PII;


//更加简洁的使用pair将 坐标存储起来
//int bfs(vector<vector<char>> &Blocks, int start_x, int start_y, int width, int height)
//{
//	queue<PII> q;
//	q.push({ start_x,start_y });
//	int cnt = 0;
//
//	while (!q.empty())
//	{
//		int now_x = q.front().x;
//		int now_y = q.front().y;
//		q.pop();
//		cnt++;
//
//		for (int d = 0; d < 4; d++)
//		{
//			int a = now_x + dx[d], b = now_y + dy[d];
//			if (a >= 0 && a < height && b >= 0 && b < width && Blocks[a][b] == '.')
//			{
//				Blocks[a][b] = '#';
//				q.push({ a,b });
//			}
//		}
//	}
//	return cnt ;
//}
//
//
//int main()
//{
//	while (true)
//	{
//		int cnt = 0;
//		int width = -1, height = -1;
//		cin >> width >> height;
//		if (width == 0) break;
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '.';
//				}
//			}
//		}
//		cnt = bfs(Blocks, start_x, start_y, width, height);
//		cout << cnt << endl;
//	}
//	return 0;
//}



//法3 使用flood fill的 dfs写法
int dfs(vector<vector<char>>& Blocks, int x, int y, int width, int height)
{
	int res = 1; //当前自己这块要计算上
	//将当前块标记为红色砖块
	Blocks[x][y] = '#';

	for (int d = 0; d < 4; d++)
	{
		int new_x = x + dx[d], new_y = y + dy[d];
		if (new_x >= 0 && new_x < height && new_y >= 0 && new_y < width && Blocks[new_x][new_y] == '.')
		{
			res += dfs(Blocks, new_x, new_y, width, height);
		}
	}
	return res;
}


//int main()
//{
//	int width = -1, height = -1;
//	while (cin >> width >> height && width!= 0)
//	{
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '.';
//				}
//			}
//		}
//		int res = dfs(Blocks, start_x, start_y, width, height);
//		cout << res << endl;
//	}
//	return 0;
//}

