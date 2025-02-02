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

// SPFA算法判断负环  关于朴素的spfa算法是用于处理稀疏图情况下 图中不存在负环问题的究极解法， 这个方法和对优化dij算法很像
// 但是有着本质的不同 使用一个队列 来放入上一次更新过程中发生变化的值  然后不断修正 直到最终队列为空为止
// 如果存在负环 那么这个队列将会一直不空 陷入死循环  那么如何使用spfa来判断负环呢

// 根据抽屉原理我们可以知道 如果一个点的最短路径 经过了 n个点 那么意味着路径上必定有一个地方的顶点编号是重复的 也就意味着存在负环
// 由于是稀疏图 因此使用邻接表存储
const int N = 10010;
int e[N], w[N], ne[N], h[N], idx;
void add(int x, int y, int z)
{
	e[idx] = y;
	w[idx] = z;
	ne[idx] = h[x];
	h[x] = idx++;
}

int n, m;
int cnt[N]; // 由于标记目前最短路经过了多少个顶点
int dis[N];
bool st[N];

bool spfa_neg() //输入为顶点编号
{
	//第一步初始化距离
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;  //这一步是为了提供最开始启动  确保程序能够正确运行下去。
	// 第二部初始化队列
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}
	// 由于负环并不一定从1号点开始 因此我们需要遍历所有的顶点 如果一个点一个点遍历 会超时  因此只需要把顶点全部放入队列中即可


	while (q.size())
	{
		auto key = q.front();
		q.pop();
		st[key] = false;

		//遍历这个顶点的所有临边
		for (int i = h[key]; i != -1; i = ne[i])
		{
			int index = e[i];
			int weight = w[i];
			//尝试更新
			if (dis[index] > dis[key] + weight)
			{
				dis[index] = dis[key] + weight;
				cnt[index] += 1; //说明经过了一个点  cnt数组++
				if (cnt[index] >= n) //说明存在负权
				{
					return true;
				}
				if (!st[index])
				{//如果这个点不在队列中 则加入并重置标志位
					q.push(index);
					st[index] = true;
				}
			}
		}
	}
	return false;
}



int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}


	if (spfa_neg())
	{
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}