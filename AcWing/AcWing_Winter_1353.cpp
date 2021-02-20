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


const int N = 1010;
int Height[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Height[i];
	}
	int res = INT_MAX;
	//我們可以通过反证法证明，最终的所有结果必定落在【0到100的区间】
	//然后结合给定的强制性条件，最高和最低不大于17
	//我们可以确认所有可能存在区间在【0，17】 到 【83，100】之间
	for (int i = 0; i <= 83; i++)
	{
		//在每个区间内，我们可以断定所有的区间，
		//如果高度本身在这个区间内，那么不用改变
		//如果高度不在这个区间内，那么直接移动到最近的边界，即为所求
		int left_bound = i;
		int right_bound = i + 17;
		int tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (Height[j] < left_bound) tmp += (Height[j] - left_bound) * (Height[j] - left_bound);
			else if (Height[j] > right_bound) tmp += (Height[j] - right_bound) * (Height[j] - right_bound);
		}
		//枚举完一个可能区间，我们比较一下最值
		res = min(res, tmp);
	}

	cout << res << endl;
	return 0;
}