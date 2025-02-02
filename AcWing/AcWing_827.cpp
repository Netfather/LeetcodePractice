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

// 根据单链表实现的思想 分别定义如下数组
const int N = 100010;
int e[N]; // 存储所有插入的元素
int ne[N]; // 存储当前分配地址 所指向的下一个地址
int pr[N]; //存储当前分配地址所指向的前一个地址

int idx = 2; //地址分配器  将输入的数字分配到唯一地址  0 1地址由头指针和尾指针代替
// 这道题和单链表最大的不同就在于 这里就需要 真实存在的头指针 和真实存在的尾指针了
int head = 0; // 头指针
int tail = 1;// 尾指针

//实现如下操作
// 在最开始的版本 我们定义的是head 为 -1 tail为0 这种方法是继承自上一题的单链表，但是这个思路在这里会非常困难
// 因为 当第一个操作为L 插入 那么就完全无法处理头节点
// 因此正确的方法是 手动指定 0 1 为头 尾指针节点  然后地址分配器就需要从2开始
// 然后这么设计的好处就是 对于这种链表只存在两种操作 插入 和 删除 然后就没有了


// 使用全新定义的 头指针 尾指针 就不需要 区别 头插入了 因为可以直接使用insert K 来实现
//void inserhead(int x)
//{
//	//将数据插入
//	e[idx] = x;
//	// 将新空间接上原来的head
//	ne[idx] = head;
//	// 将原head指针的pr指向新空间
//	pr[ne[idx]] = idx;
//	pr[idx] = 0; //pr指向最前的头地址
//	// 更新head
//	head = idx++;
//}
//
//void inserttail(int x)
//{
//	//将数据插入
//	e[idx] = x;
//	ne[tail] = idx;
//	pr[idx] = tail;
//
//	ne[idx] = 1; // ne指向最后的尾巴地址
//	//维护tail
//	tail = idx++;
//}

void deletee(int k)
{
	//之所以k要+1 的传入进来 是因为地址分配器从2 开始 你第一个插入的数字 分配到的地址为2
	ne[pr[k]] = ne[k];
	pr[ne[k]] = pr[k];
}

void insertRight(int k, int x)
{
	e[idx] = x;

	ne[idx] = ne[k];
	pr[ne[k]] = idx;

	pr[idx] = k;
	ne[k] = idx++;
}

int main()
{
	// 初始形态
	ne[head] = tail;
	pr[tail] = head;

	int m;
	cin >> m;
	while (m--)
	{
		string Op;
		cin >> Op;
		if (Op == "L")
		{
			int x;
			cin >> x;
			insertRight(head, x);
		}
		else if (Op == "R")
		{
			int x;
			cin >> x;
			insertRight(pr[tail], x);
		}
		else if (Op == "D")
		{
			int k;
			cin >> k;
			deletee(k + 1);
		}
		else if (Op == "IR")
		{
			int k, x;
			cin >> k >> x;
			insertRight(k + 1, x);
		}
		else
		{
			int k, x;
			cin >> k >> x;
			insertRight(pr[k + 1], x);
		}
	}
	for (int i = ne[head]; i != tail; i = ne[i]) cout << e[i] << " ";

	return 0;
}