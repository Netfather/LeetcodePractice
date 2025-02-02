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

// 对于单链表 使用两个数组 一个为e数组 存储所有存在的位置 ne数组 存储所有e数组对应位置的下一个索引
// 还需要一个查找表 这个查找表对应的是 第k个插入的数字 对应与e的哪个下标索引
// 一次过！！！！ 牛逼！！
// 由于题目给的k是从1开始的 所以所有cin的k 要减去1

const int N = 100010;
int e[N];  //存储每一次插入的元素   表示第i个插入的元素是多少
int ne[N]; // 存储第i个元素的下一个元素的索引是多少
int idx = 0; // 这个可以视为分配器，用于分配每一个元素的唯一序列标志
int head = -1; // 用于保存这个链表的表头下标索引  这里是-1 是因为在刚开始的时候 ne[idx] = head 那么使用-1 就可以正好将表位元素赋值成功
// 在最一开始没有数字的时候 我们可以视为表头在0的右边 也就是-1的位置

// 在表头后面插入一个数
void insert(int x)
{
	// 首先不管三七二十一 将数字插入e中
	e[idx] = x;
	// 将这个数的下一个指针位置指向现在的表头
	ne[idx] = head;
	//然后更新现在的head;
	head = idx++;
}
// 删除第k个插入的数字
void deletee(int k)
{
	// 由于idx只有在插入时才会计数  所以这里k其实就是e的下标索引
	if (k != -1)
	{
		ne[k] = ne[ne[k]];
	}
	//如果删除的是头节点
	else
	{
		head = ne[head];
	}
}
// 在第k个插入的数字后面插入一个数x
void insertK(int k, int x)
{
	// 开辟新空间
	e[idx] = x;
	// 将原来的ne保存到新开辟的空间
	ne[idx] = ne[k];
	// 将当前新空间接入k后面
	ne[k] = idx++; //注意这个++其实是省略了步骤  这一行同时完成了两件事 1.将新空间接入k之后，2. 为下一个用到的空间++
}


int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		char O;
		cin >> O;
		if (O == 'H')
		{
			int x;
			cin >> x;
			insert(x);
		}
		else if (O == 'I')
		{
			int k, x;
			cin >> k >> x;
			insertK(k-1, x);
		}
		else
		{
			int k;
			cin >> k;
			deletee(k-1);
		}
	}

	//输出
	for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";


	return 0;
}