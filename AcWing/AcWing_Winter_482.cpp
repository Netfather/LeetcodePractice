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

//首先我们应当注意到，对于这个问题，最关键的点就是中间最高的同学
//在已知中间最高同学的基础上，我们只需要求得两个序列，一个是最长上升子序，一个是最长下降子序
//而且由于在已知中间最高同学的基础上，这两个子序是完全独立的，因此此时就可以很容易求得最少需要出列几个同学

const int N = 110;
int height[N];
int dp_up[N]; //这个状态数组表示，从1到i中间，最长上升子序的长度
int dp_down[N];//这个状态数组表示，从i到N结束，最长下降子序的长度

void Solv_up(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dp_up[i] = 1; //首先 自己本身一定是一个上升子序
		//然后 不计算自己，统计从头开始，所有的比自己小的数
		for (int j = 1; j < i; j++)
		{
			//由于题干是严格的小于，因此这里也需要严格小于
			if (height[j] < height[i])
			{
				dp_up[i] = max(dp_up[i], dp_up[j] + 1);
			}
		}
	}
	return;
}

void Solv_down(int n)
{
	for (int i = n; i >= 1; i--)
	{
		dp_down[i] = 1;
		// 统计所有从数组尾部开始，所有的比自己小的数字
		for (int j = n; j > i; j--)
		{
			if (height[j] < height[i])
			{
				dp_down[i] = max(dp_down[i], dp_down[j] + 1);
			}
		}
	}
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
	}
	Solv_up(n);
	Solv_down(n);

	//然后遍历统计
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(dp_up[i] + dp_down[i], res);
	}
	cout << n - res + 1 << endl;
	return 0;
}