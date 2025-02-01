//思路： 标准的flood fill算法，使用dfs来进行递归计算连通区域的个数
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//#include <climits>
//using namespace std;
//
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };  //定义联通区域方向
//const int N = 110;
//bool visited[N][N];


//void dfs(vector<vector<bool>> &visited, vector<string> &Grid, int x, int y, int width, int height)
//{
//	visited[x][y] = false;
//
//	for (int d = 0; d < 4; d++)
//	{
//		int new_x = x + dx[d], new_y = y + dy[d];
//		if (new_x >= 0 && new_x < height && new_y >= 0 && new_y < width && Grid[new_x][new_y] == '1' && visited[new_x][new_y])
//		{
//			dfs(visited, Grid, new_x, new_y,width,height);
//		}
//	}
//	return;
//}
//
//
//
//int main()
//{
//	int T = -1;
//	cin >> T;
//
//	for (int num = 1; num <= T; num++)
//	{
//		cout << "Case #" << num << ":"<<endl;
//		int res = 0;
//		int width = -1, height = -1;
//		cin >> height >> width;
//		vector<string> Grid(height,"");
//		for (int i = 0; i < height; i++) cin >> Grid[i];
//
//
//		int ope = -1;
//		cin >> ope;
//		for (int ope_num = 0; ope_num < ope; ope_num++)
//		{
//			char Mode = 'z';
//			cin >> Mode;
//			if (Mode == 'M')
//			{
//				int x, y;
//				char value;
//				cin >> x >> y >> value;
//				Grid[x][y] = value;
//			}
//			else
//			{
//				vector<vector<bool>> visited_org(height, vector<bool>(width, true));
//				int res = 0;
//				for (int i = 0; i < height; i++)
//				{
//					for (int j = 0; j < width; j++)
//					{
//						if ((visited_org[i][j]) && Grid[i][j] == '1')
//						{
//							dfs(visited_org,Grid, i, j, width, height);
//							res++;
//						}
//					}
//				}
//				cout << res<<endl;
//			}
//		}
//	}
//	return 0;
//}
//void dfs(vector<string> &Grid, int x, int y, int width, int height)
//{
//	visited[x][y] = false;
//
//	for (int d = 0; d < 4; d++)
//	{
//		int new_x = x + dx[d], new_y = y + dy[d];
//		if (new_x >= 0 && new_x < height && new_y >= 0 && new_y < width && Grid[new_x][new_y] == '1' && visited[new_x][new_y])
//		{
//			dfs(Grid, new_x, new_y, width, height);
//		}
//	}
//	return;
//}
//
//
//
//int main()
//{
//	int T = -1;
//	cin >> T;
//
//	for (int num = 1; num <= T; num++)
//	{
//		cout << "Case #" << num << ":" << endl;
//		int res = 0;
//		int width = -1, height = -1;
//		cin >> height >> width;
//		vector<string> Grid(height, "");
//		for (int i = 0; i < height; i++) cin >> Grid[i];
//
//
//		int ope = -1;
//		cin >> ope;
//		for (int ope_num = 0; ope_num < ope; ope_num++)
//		{
//			char Mode = 'z';
//			cin >> Mode;
//			if (Mode == 'M')
//			{
//				int x, y;
//				char value;
//				cin >> x >> y >> value;
//				Grid[x][y] = value;
//			}
//			else
//			{
//				memset(visited, 0, sizeof visited);
//				int res = 0;
//				for (int i = 0; i < height; i++)
//				{
//					for (int j = 0; j < width; j++)
//					{
//						if ((visited[i][j]) && Grid[i][j] == '1')
//						{
//							dfs(Grid, i, j, width, height);
//							res++;
//						}
//					}
//				}
//				cout << res << endl;
//			}
//		}
//	}
//	return 0;
//}


