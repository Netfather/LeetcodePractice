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
int w[N];


//关于并查集，最主要的操作是find操作 这个操作会返回查询的某个点他的祖节点。 同时这个操作在查找的同时将所有路径上经过的点全部指向祖宗节点
int find(int a)
{
	//由于在初始化过程中，每一个数字在数组w中都被赋予了一个独特的编号，也可以理解为地址 在最开始  每一个自己的地址指向的都是自己，标志自己就是自己的祖宗节点
	// 不论并查集如何修改，只有祖宗节点的地址，查出来的值  才会等于自己，其他点全部都会变成其他的 基于这点观察
	if (w[a] != a) w[a] = find(w[a]);  // 如果a节点自己不是祖宗节点，那就去寻找a指向的那个节点的祖宗节点，找到之后，将该祖宗节点赋值给w[a]
	return w[a];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) w[i] = i; //将查询数组分别输入  使得 每一个1 2 3 这样的地址 对应的值为1 2 3 它本身 
	// 也就意味着在最开始状态下 n个数字全是祖节点 然后开始处理指定
	while (m--)
	{
		char Op;
		int a, b;
		cin >> Op >> a >> b;
		int x = find(a);
		int y = find(b);
		if (Op == 'M')
		{
			w[x] = y; // 修改x的祖宗节点 指向y
		}
		else
		{
			if (x != y) cout << "No" << endl;
			else cout << "Yes" << endl;
		}

	}
	return 0;
}