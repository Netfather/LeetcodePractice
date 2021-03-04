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

// 这道题是要找到从小到大的第k个数，仔细思索快速排序中，每次确定的是key对应的位置，因此在知道key对应的下标之后，我们可以一次是快排一个区间
const int N = 100010;
int w[N];
// 注意这道题的核心在于这个函数他定义的是 start 到 end范围内 第k个数是多少，注意这个k应当是从start开始算起，而不应当将整个数组的k传入，因此
// 
bool QuickSortK(int start, int end, int k)
{
	if (start >= end) return true;

	auto key = w[start + end >> 1];

	int l = start - 1, r = end + 1;
	while (l < r)
	{
		while (w[++l] < key);
		while (w[--r] > key);
		if (l < r) swap(w[l], w[r]);
	}
	//核心： 这里我们需要比较的是，我们完成双指针算法之后 r指向目前正确位置的位置，将r - start+ 1 得到对应于当前数组，k的位置，然后根据这个来划分
	// 典型错误： 错误的将r 作为正确位置导致没有进行 r - start+ 1 导致 出现问题
    // 我们需要实时维护 在完成一次QuickSort过程之后，左边已经排序好的长度到底有多少，
	if (r - start + 1 >= k) // 统计规定区域左边有多少个数字
	{
		if (QuickSortK(start, r, k)) return true;
	}
	else
	{
		if (QuickSortK(r + 1, end, k - (r - start + 1))) return true;

	}

	return false;
}


int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	QuickSortK(1, n, k);
	cout << w[k] << endl;

	return 0;
}