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

//典型的双指针问题  即 结果不会回退。。

// 以上都不对 这道题其实还是那个 关键 如何将问题退化为一个非常简单的问题。
// 首先我们可以发现一个核心点，  如果一个新的数字加入了区间，如果这个数字使得当前区间的平均数发生了变化，
// 1. 如果使平均数向上变化， 例如 1 3   新加入的3导致平均数从1 变化为2    那么我们一定可以通过只选3 来找到最优解
// 2. 如果使平均数向下变化， 例如 3 1   那么我们一定可以通过之选前半部分 来找到最优解
// 所以 能够使得长度延展的唯一可能就是   当前区间所有数字都一样

// 基于这个论断 我们可以得到   所有不相等的数字各自一定为一个区间 所有相等的数字全部为一个区间 然后遍历一遍找到最大值即可。

//为了方便起见  定义前缀和数组
typedef long long LL;
const int N = 100010;
LL a[N];
LL s[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		//预处理前缀和数组
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

		//双指针
		int i = 1, j = 2;  //i指向左端点  j指向右端点
		int len = 1;  // 结果暂存 
		double res = double(a[1]); //平均数暂存
		for (; j <= n; j++)
		{
			if (a[i] != a[j])  //如果不相等 就要计算一下当前区间的平均数并判定以下 当前区间是否为目前的最优解
			{
				double tempres = double(s[j - 1] - s[i - 1]) / double(j - i);
				if (tempres > res  ||  (tempres == res && j - i > len))  //两个条件 分别对应 题目的两个条件
				{
					len = j - i;
					res = tempres;
				}
				//更新新的区间
				i = j;
			}
		}
		//处理一下尾巴  这个是为了防止 最后一个段 没有处理导致的
		if (i != j)
		{
			double tempres = double(s[j - 1] - s[i - 1]) / double(j - i);
			if (tempres > res || (tempres == res && j - i > len))
			{
				len = j - i;
				res = tempres;
			}
		}
		cout << len << endl;
	}


	return 0;
}