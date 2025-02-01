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

// 思路： 这道题很容易想明白，由于是子序列 不是连续子序列，因此对于a中的数字，直接按顺序找到第一个在b中与之匹配的点就可以，因为如果这个点匹配成功了
//后面的点也会匹配成功，不存在错位的情况  所以关键是子序列

const int N = 100010;
int a[N];
int b[N];


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0, j = 0;
	for (; j < m; j++)
	{
		if (b[j] == a[i]) i++;
		// 如果匹配上 就将i移动位置 
		if (i == n)
		{
			cout << "Yes" << endl;
			return 0;
		}
		//匹配不上 就一直移动j
	}
	cout << "No" << endl;

	return 0;
}