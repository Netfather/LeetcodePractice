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

//就像是  拆线纺织  重新组织一下即可 非常简单
// 组几个实例  就知道究竟应该怎么做了
// 大致思路是 s按位取 然后  对结果的c  从中间往两边进行赋值


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "?" + s;
	string c = s;

	int k = n / 2;
	// 两轮 从 k开始  每次根据中心点 进行赋值
	if (n % 2)
	{
		c[n / 2 + 1] = s[1]; //中心点赋值
		for (int i = 2; i <= n; i++)
		{
			c[k] = s[i];
			i++;
			c[n + 1 - k] = s[i];
			k--;
		}
	}
	else
	{
		//偶数不存在中心点赋值
		for (int i = 1; i <= n; i++)
		{
			c[k] = s[i];
			i++;
			c[n + 1 - k] = s[i];
			k--;
		}
	}
	for (int i = 1; i <= n; i++) cout << c[i];


	return 0;
}