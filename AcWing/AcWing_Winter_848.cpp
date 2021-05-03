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

//这道题的思路核心就在于活用 bfs 的结构  配合 入度数组来进行解答。
// 根据拓扑排序的思想，我们可以知道  如果一个顶点 他的入度为0 说明 没有任何边指向他 那么也就说明没有任何点在他前面，那么他就一定是拓扑排序排在前面的点

const int N = 1000010;
int e[N], idx, h[N], ne[N];

int rudu[N];   //记录某个顶点的入度是多少  索引存储的是节点编号！！ 不是地址分配器给的地址！！
int n, m;
vector<int> res;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool topsort()
{
	//初始化队列于相应的存储数组
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (rudu[i] == 0) q.push(i);
	}

	while (q.size())
	{
		int key = q.front();
		res.push_back(key); // 每次从队列中弹出的元素都是拓扑排序中的正确序列
		q.pop();

		// 将这个点指向的所以其他边的入度减少
		for (int i = h[key]; i != -1; i = ne[i])
		{
			int index = e[i];
			rudu[index]--;
			if (rudu[index] == 0) q.push(index);
		}

	}
	if (res.size() != n) return false;
	return true;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		rudu[b]++;   // 说明b号顶点  的入度++
	}
	if (topsort())
	{
		for (auto i : res) cout << i << " ";
	}
	else cout << -1;

	return 0;
}