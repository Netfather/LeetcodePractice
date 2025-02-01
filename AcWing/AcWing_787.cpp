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
int w[N], tmp[N];

void MergeSort(int start, int end)
{
	//终止条件判断
	if (start >= end) return;
	// 划分两个子问题
	int m = start + end >> 1;
	// 分别进行归并
	MergeSort(start, m);
	MergeSort(m + 1, end);
	//完成归并后进行排序
	int l_1 = start, l_2 = m + 1;
	int cur = 0;
	// 先用双指针，将两个数组进行首元素比较，将比较结果存入tmp中
	while (l_2 <= end && l_1 <= m)
	{
		if (w[l_1] >= w[l_2])
		{
			tmp[cur++] = w[l_2++];
		}
		else if (w[l_1] < w[l_2])
		{
			tmp[cur++] = w[l_1++];
		}
	}
	// 再查缺补漏，将两个分开的组中，其中没有跑完的数组接到tmp后面
	while (l_1<= m) tmp[cur++] = w[l_1++];


	while (l_2 <= end) tmp[cur++] = w[l_2++];


	//将排序好的数组排到后面
	for (int i = start, k = 0;i <= end; i++,k++)
	{
		w[i] = tmp[k];
	}

	return;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	MergeSort(1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;



	return 0;
}