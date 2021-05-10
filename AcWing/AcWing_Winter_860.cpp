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

//关于二分图的判定  一个无向图是否是二分图的意思是指 能否使用两种不同的颜色，将一幅图完美的染成两个部分，
// 对于这个问题 我们可以用 1 2 来分别染色不同的顶点 使用类似于flood fill算法
// 这道题和 flood fill算法几乎是完全一致  只不过将相关的思想搬运到了 图论中来
int n, m;
const int N = 1000010;
int e[N], ne[N], h[N], idx;
void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = h[x];
	h[x] = idx++;
}

int colors[N]; //用于查询某个顶点被染色成什么颜色
bool Pending(int x,int color)  //将编号为x的顶点 染色为color颜色
{
	//if (colors[x])
	//{
	//	if (colors[x] == color) return true;
	//	else return false;
	//}
	//如果这个点没有被染色
	colors[x] = color; //现在被染色了 然后遍历一下这个点的所有临边
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int index = e[i];
		if (colors[index] && colors[index] != 3 - color) return false;
		if (!colors[index])  //如果这个点没有被填充颜色 那么就进行dfs过程
		{
			if (!Pending(index, 3 - color)) return false;  //如果一个点可以被染色为目标颜色 就进行染色 然后
		}
	}
	return true;
}


int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	//由于可能这个图存在某些点不连通 所以必须遍历一遍所有的顶点
	for (int i = 1; i <= n; i++)
	{
		if (!colors[i] && !Pending(i, 1))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}