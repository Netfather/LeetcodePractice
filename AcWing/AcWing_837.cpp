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

const int N = 1000010;
int p[N]; //输入索引为： 图中每个点的地址编号   输出结果为：每个点的地址编号对应的上一级地址编号
int num[N]; //输入索引为： 祖宗节点的地址编号  输出索引为： 该祖宗节点所代表的连通块中点的数量 注意这里只有祖宗节点查询到的值是正确的 其他点都是错误的

int find(int x)
{
	if (p[x] != x)
	{
		p[x] = find(p[x]);
	}
	return p[x];
}

void connect(int a, int b)
{
	if (a == b) return;  //自己和自己连一条边 没有意义 直接返回
	int x = find(a);
	int y = find(b);
	p[x] = y; //ab不相等 我们随便将ab的祖宗节点连起来就可以了
	// 维护祖宗节点的cnt
	num[y] += num[x];
}

bool query1(int a, int b)
{
	if (a == b)
	{
		return true;
	}
	else if (find(a) != find(b))
	{
		//cout << "No" << endl;
		return false;
	}
	else
	{
		//cout << "Yes" << endl;
		return true;
	}
}

int query2(int a)
{
	return num[find(a)];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		num[i] = 1;
		p[i] = i;
	}
	while (m--)
	{
		string Op;
		int a, b;
		cin >> Op >> a;
		if (Op == "C")
		{
			cin >> b;
			if ( !query1( a,  b)) connect(a, b);
		}
		else if (Op == "Q1")
		{
			cin >> b;
			if (query1(a, b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else
		{
			cout << query2(a) << endl;
		}
	}

	return 0;
}