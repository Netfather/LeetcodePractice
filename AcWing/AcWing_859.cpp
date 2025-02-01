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

//同样 根据朴素版dij算法的优化启发，同样可以指导如何优化Prim算法  
// Kruskal算法在时间复杂度上非常有优势，并且这个算法在某种程度上是贪心和并查集问题的合并
// 我们将所有的边保存下来，做一个排序，然后遍历所有的边权，如果这个边权连接的两个点没有联通 就直接加入最小生成树即可

const int N = 200010;
struct Edges
{
	int w;
	int a;
	int b;

	 bool operator< (const Edges& tmp) const
	{
		return w < tmp.w;
	}
}edges[N];
int p[N]; //并查集使用 用于查询编号的祖宗节点
int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int n, m;
int main()
{
	int res = 0;
	int cnt = 1;
	cin >> n >> m;
	//初始化所有的祖宗节点
	for (int i = 1; i <= n; i++) p[i] = i;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = { z,x,y };
	}
	sort(edges, edges + m);
	for (int i = 0; i < m; i++)
	{
		auto key = edges[i];
		int x = find(key.a);
		int y = find(key.b);
		if (x != y)
		{
			++cnt;
			res += key.w;
			p[x] = y;
		}
	}
	if (cnt < n) cout << "impossible" << endl;
	else cout << res;
	return 0;
}