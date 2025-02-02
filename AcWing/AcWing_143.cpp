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

//这道题是Trie树的变种   异或计算的本质就是 不同的为1  相同的为0
// 对于输入的整数 我们把他转为一个string类型 二进制 存储到Trie树中
// 然后每多一个数，我们就在树中进行寻找之前插入的数字，尽量寻找每一位完全不同的数字

const int N = 100010 * 31; //由于一共有100010数字，每个数字有32位 所以一共要开这么大的大小
int son[N][2];
//int cnt[N]; //注意到这里是完全每一位填满的32位，所以我们不需要使用cnt数字来存储结束位置 
int idx = 1; // 地址分配器
void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1; //分理出每一位 从最高位开始
		if (!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
	}
	return;
}
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
		if (!son[p][!u])
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
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		insert(tmp);
		res = max(res, Query(tmp));
	}
	cout << res;


	return 0;
}