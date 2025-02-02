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

//树型dp大致都拥有相似的特征，在一个树中如何实现dp
// 考虑维护如下一个dp 模式  f[u,0] 表示 以u为根，但是不包含u的所有邀请方案     
// f[u,1] 表示以u为根，但是包含u的所有邀请方案
// 考虑状态转移，我们从root开始，递归的计算所有满足题意的方案，并进行维护
// 如果 某个根节点确定被选择了 那么他的所有子节点一定不可能被选择
// 如果 某个根结点确定没选， 那么他的所有子节点可选 可不选
const int N = 6010;
int e[N], ne[N], h[N], idx;
void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = h[x];
	h[x] = idx++;
}

int w[N]; //存储快乐指数
int has_father[N];// 用于表示某个结点他的父结点是谁  用于找到这个树的root结点
int f[N][2]; //用于存储计算结果

int Find(int root,int flag)
{
	if (f[root][0] != -1 && f[root][1] != -1) return max(f[root][0], f[root][1]);
	int res_0 = 0;
	int res_1 = w[root]; //如果为1 则需要将指数加上当前的root

	//遍历一下所有临边
	for (int i = h[root]; i != -1; i = ne[i])
	{
		int index = e[i];
		int index_0 = Find(index, 0);
		int index_1 = Find(index, 1);
		res_1 += index_0; //如果当前根节点选了1  那么他的子树是一定不能选的
		res_0 += max(index_0, index_1); // 如果当前根节点选了0 那么他的子树可选可不选
	}
	f[root][0] = res_0;
	f[root][1] = res_1;
	if (flag == 0) return f[root][0];
	else return f[root][1];
}



int main()
{
	memset(h, -1, sizeof h);
	memset(f, -1, sizeof f);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int L, K;
		cin >> L >> K;
		add(K, L);
		has_father[L] = K;
	}
	//寻找整个树的根结点
	int root =1;
	while (has_father[root]) root = has_father[root];
	Find(root, 0);
	cout << max(f[root][0], f[root][1]) << endl;
	return 0;
}