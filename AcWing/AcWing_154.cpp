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

//先不管最大值的部分 我们考虑 k的最小值 由于涉及到是否出窗口的问题 我们的队列存储的是索引
//  站在一个马上要被读入的i位置 往前看 最小值队列
// 首先判定 对头元素是否超出了 窗口 是就弹出队首
// 然后判定 队尾元素是否比当前读入的元素更大。是就弹出队尾，因为如果这个数是之前读入的，但是却比当前读入的大，那么就永远不可能被取到了
// 最后输出结果即可
// 这道题 还需要稍微处理一下第一个窗口的元素
const int N = 1000010;
int w[N];



int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> w[i];

	deque<int> small;  //存储的是对应值的索引  这里由于同时要处理对头和队尾 因此需要使用双端队列

// 先把前k个数字入队
	small.push_back(0); // 起始值入队
	// 如下处理第一个窗口的所有数字，第一个窗口不需要考虑超过 因此只需要保证找到前k的最小值  然后放入small 队列即可
	for (int i = 1; i < k; i++)
	{
		while (!small.empty() && w[small.back()] >= w[i]) small.pop_back();
		small.push_back(i);
	}
	cout << w[small.front()] << " ";
// 开始滑动窗口
	for (int i = k; i < n; i++)
	{
		while (!small.empty() && small.front() + k <= i) small.pop_front(); // 当首元素索引 超过k窗口大小 就要pop
		while (!small.empty() && w[small.back()] >= w[i]) small.pop_back();
		// 在push之前还有一个判断 如果 当前的首元素超出窗口范围？
		small.push_back(i);
		cout << w[small.front()] << " ";
	}
	cout << endl;

	//处理big情况
	deque<int> big;
	big.push_back(0);
	for (int i = 1; i < k; i++)
	{
		while (!big.empty() && w[big.back()] <= w[i]) big.pop_back();
		big.push_back(i);
	}
	cout << w[big.front()] << " ";
	for (int i = k; i < n; i++)
	{
		while (!big.empty() && big.front() + k <= i) big.pop_front();
		while (!big.empty() && w[big.back()] <= w[i]) big.pop_back();
		big.push_back(i);
		cout << w[big.front()] << " ";
	}

	return 0;
}