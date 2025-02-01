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

const int N = 100010;
int h[N], e[N], ne[N];    //e存储的是 对应的点的编号     h通过点的编号索引 获得地址    ne 获得地址
int idx; //地址分配器
bool status[N];
int n;
int ans = N;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

// 以u为根节点 他的各个子树中 连通块数量的最大值
int dfs(int u)
{
	status[u] = true;  //已经搜索过了
	int res = 0;
	int sum = 1;    //从1开始是因为要计算自身
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int index = e[i];
		if (status[index] == false)
		{
			int tmp = dfs(index);  // 拿到以那个节点为根节点的最大连通块数量
			res = max(res, tmp);   //比较一下
			sum += tmp;   // 算上自己
		}
	}
	
	res = max(res, n - sum); // 选择u节点为重心，最大的 连通子图节点数    这里的原因是因为需要计算出不能由这个结点走到的其他地方的连通块
	ans = min(res, ans); //遍历过的假设重心中，最小的最大联通子图的 节点数
	return sum;
}


int main()
{
	memset(h, -1, sizeof h);
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}