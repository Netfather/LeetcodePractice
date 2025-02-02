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

// Trie树的根本就是 针对出现的字母很少，但是构成的字符串很多，将所有的字符串 挂到一棵树上，相同的位置过来的字符 共享相同地址

const int N = 100010;
int son[N][26];  //这个树存储数字本身，含义为  从第i个地址往后看一个字符，对应字符的地址是哪里，如果不存在就创建，存在就跳跃过去
int idx = 1; //0号地址预留给root 也就是第一个位置   和单链表 双链表一样 这个是地址分配器 和Y总写的不一样 因为为了保持 和单链表统一 这一idx直接从1开始
int cnt[N]; //用于标志结尾

void insert(string a)
{
	int p = 0;
	for (int i = 0; i < a.length(); i++)
	{
		// 首先站在0位置 也就是root节点 往后看第一个字符 是否存在 
		if (!son[p][a[i] - '0']) son[p][a[i] - '0'] = idx++;// 不存在就分配一个
		p = son[p][a[i] - '0']; //此时不论是否存在 我们都能够找到下一个地址的跳板 将跳板赋值给下一个的起点p
	}
	++cnt[p]; // 循环结束后 p存储的就是最后一个节点的地址，所以只需要将地址作为索引 cnt对应的索引++即可
}

int Query(string a)
{
	int p = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (!son[p][a[i] - '0']) return 0;
		p = son[p][a[i] - '0'];
	}
	return cnt[p];
}



int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		char Op;
		string a;
		cin >> Op >> a;
		if (Op == 'I') insert(a);
		else
		{
			cout << Query(a) << endl;;
		}
	}
	return 0;
}