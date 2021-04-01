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

int n;
const int N = 14;
char g[N][N];

bool Zong[N];
bool Zduijiao[2*N];
bool Fuduijiao[2 * N];

// dfs通杀的方法就是  第一区写终止条件 第二区写一个循环 遍历这一层所有的可能性， 同时这一区还要融合条件判断，状态改写，恢复现场
// 这道题还有个核心点就是 如何快速判断两个点是否在同一个对角线上  使用 截距判断即可  y= x + c  y = -x + c
void dfs(int depth)
{
	if (depth >= n)
	{
		//说明已经成功找到了一组解
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
		if (!Zong[i] && !Zduijiao[depth + i] && !Fuduijiao[N + depth - i])   //满足纵行没有数字，对角没有数字 意味着这个点可以填皇后
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