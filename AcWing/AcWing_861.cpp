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


////匈牙利算法  进行二分图的最大匹配  题目是给定一个二分图，让我们找到使得二分图能够最大限度的连接两个不同的部分的一种组合
// 这个算法 大致就是 构造一个find函数 这个函数负责为给定的顶点 分配一个 对象，
// 由于这道题需要快速的找到 某个顶点对应的临边有哪些 因此这里还是需要使用邻接表来存储对应的信息
const int M = 100010;
const int N = 510;
int e[M], ne[M], h[N], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int n1, n2, m;
int match[N]; //用于表明 某个顶点 对应的另一半编号是多少
// 一定要有一个 st 用于表明 在本次模拟中 对面是否已经搜索过了 如果搜索过 就不再进行递归 否则会陷入死循环
int res = 0;

bool find(int x)
{
	//遍历一下x的所有临边
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int index = e[i];
		//如果对应的顶点没有匹配 或者 如果对应的顶点已经有匹配对象了 我们就努力尝试去让对面的顶点去重新寻找一个对象
		if (!match[index] || find(match[index]))
		{
			match[index] = x;
			return true;
		}

	}
	//尝试了所有办法 都不能匹配上 就返回false
	return false;
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n1 >> n2 >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
	}
	for (int i = 1; i <= n1; i++)
	{
		memset(match, 0, sizeof match);
		//遍历左半边的所有顶点 , 如果能分配到编号 就将res++ 
		if (find(i)) res++;
	}
	cout << res << endl;
	return 0;
}

//匈牙利算法  进行二分图的最大匹配  题目是给定一个二分图，让我们找到使得二分图能够最大限度的连接两个不同的部分的一种组合
// 这个算法 大致就是 构造一个find函数 这个函数负责为给定的顶点 分配一个 对象，
// 由于这道题需要快速的找到 某个顶点对应的临边有哪些 因此这里还是需要使用邻接表来存储对应的信息
//const int M = 100010;
//const int N = 510;
//int e[M], ne[M], h[N], idx;
//void add(int a, int b)
//{
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//int n1, n2, m;
//int match[N]; //用于表明 某个顶点 对应的另一半编号是多少
//bool st[N]; //用于表示n2点集中是否已经被匹配
//int res = 0;
//
//bool find(int x)
//{
//	//遍历一下x的所有临边
//	for (int i = h[x]; i != -1; i = ne[i])
//	{
//		int index = e[i];
//		if (!st[index])
//		{
//			//如果对应的顶点恰好没有被匹配 我们就直接匹配上这个点
//			st[index] = true;
//			// 如果这个顶点没有match 或者她match的对象能够移情别恋 那么我们就将这个x写入match中
//			if (!match[index] || find(match[index]))
//			{
//				match[index] = x;
//				return true;
//			}
//		}
//	}
//	//尝试了所有办法 都不能匹配上 就返回false
//	return false;
//}
//
//
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n1 >> n2 >> m;
//	while (m--)
//	{
//		int x, y;
//		cin >> x >> y;
//		add(x, y);
//	}
//	for (int i = 1; i <= n1; i++)
//	{
//		memset(st, false, sizeof st);  //每轮模拟之前 统一将st数组清空
//		//遍历左半边的所有顶点 , 如果能分配到编号 就将res++ 
//		if (find(i)) res++;
//	}
//	cout << res << endl;
//	return 0;
//}