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

//堆是一种完美的完全二叉树，然后这种二叉树是按照列表的形式存储的 
// 这种由列表存储的完美二叉树拥有一个非常好的性质 已知某个根节点的下标为u 那么他的左节点必定是2u 右节点索引必定是2u+1
// 构造这种树必须满足 任意一个根节点 它的值 一定比左右两个节点都要小  针对这个递归条件  完成down up两个操作 就可以实现几乎所有的堆操作
const int N = 100010;
int w[N];
int mysize = 0;

// 主要实现 两个递归操作 down 和 up
void down(int u)
{
	int t = u; //假定输入的地址就是最小值  最小值存在u中
	if (2 * u <= mysize && w[2 * u] < w[t]) t = 2 * u;
	if (2 * u + 1 <= mysize && w[2 * u + 1] < w[t]) t = 2 * u + 1;

	if (t != u)
	{
		swap(w[t], w[u]);
		down(t);
	}
	return;
}

void up(int u)
{
	int t = u;
	if (w[u / 2] < w[t]) t = u / 2;

	if (t != u)
	{
		swap(w[t], w[u]);
		up(t);
	}
	return;

}



int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> w[i];
	mysize = n;

	//初始化整个堆
	for (int i = n / 2; i > 0; i--) down(i);

	while (m--)
	{
		cout << w[1] << " ";
		w[1] = w[mysize--];
		down(1);
	}
	return 0;

}
