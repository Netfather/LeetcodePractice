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
// 这道题的相关要点
// 第一 对于连续子序列的异或和 结合 前缀和思想我们可以将数组处理成w[n]数组，是的 w[j] ^ w[i-1] = ai^ai+1^ai+2……aj
// 第二 然后参考 最大异或对的思路，我们就可以得到一个数组中任意子数组的最大异或和
// 第三 最后考虑 窗口大小m，这意味着我们每当滑动窗口往前移动一格 就需要将trie树中删除掉一个元素。


//如何吧 连续子数组转换为 两个任意数字的和？
//那么就将这个数列a 处理为 a0 a0^a1 a0^a1^a2 这种形式 会发现这个形式和前缀和完全一致 并且实现了转换
// 然后使用Trie数的方法，将任意两个数字最大值找到 

// 这道题是Trie树的变种   异或计算的本质就是 不同的为1  相同的为0
// 对于输入的整数 我们转换为二进制 存储到Trie树中
// 然后每多一个数，我们就在树中进行寻找之前插入的数字，尽量寻找每一位完全不同的数字

const int N = 100010 * 31; //由于一共有100010数字，每个数字有32位 所以一共要开这么大的大小
int son[N][2];
int idx = 1; // 地址分配器
int a[N], w[N];
int cnt[N]; //为了实现删除掉Trie树中的某个数  需要加入cnt进行判断

void insert(int x, int v)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //分理出每一位 从最高位开始
		if (!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
		cnt[p] += v;
	}
	return;
}
// 注意 这个deletee不能粗暴的直接将某个位置赋0 因为如果一个数字和这个x前面所有高位都相同  会因为这种删除方式导致这个
// 和 x具有相同高位的数字无法遍历掉
// void deletee(int x)
// {
// 	int p = 0;
// 	for (int i = 30; i >= 0; i--)
// 	{
// 		int u = x >> i & 1; //分理出每一位 从最高位开始
// 		p = son[p][u];
// 		son[p][u] = 0; //删除这个导入的数字
// 	}
// 	return;
// }

//Query函数负责在整个树中查找，找到最能匹配上 的最大值
int Query(int x)
{
	int p = 0;
	int res = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //分离每一位，从最高位开始 
		//我们每次尽量走不同的位置

		//很遗憾 不同位置的子节点不存在
		if (!cnt[son[p][!u]])
		{
			p = son[p][u];
			res = res * 2 + u;
		}
		else
		{
			p = son[p][!u];
			res = res * 2 + !u;
		}
	}
	//找到目前存储的所有数字中 最优的结果res
	return res ^ x; //返回异或结果
}

int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	w[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		w[i] = w[i - 1] ^ a[i];
	}
	int res = INT_MIN;
	//先处理第一个M大小的窗口
	for (int i = 0; i <= m; i++)
	{
		insert(w[i], 1);
		res = max(res, Query(w[i]));
	}
	//再处理后续窗口
	for (int i = m + 1, j = 0; i <= n; i++, j++)
	{
		insert(w[j], -1); //先从trie树中删除
		insert(w[i], 1);
		res = max(res, Query(w[i]));
	}
	cout << res << endl;
	return 0;
}