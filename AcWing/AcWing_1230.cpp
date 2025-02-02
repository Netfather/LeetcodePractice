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

//思路，使用前缀和思想，将这道题转换为 问给你一个数组，求问
//有多少个点对，使得两者相减为K的倍数
// 那么进一步可以转换为，求问一个数组，使得数组中两点除以K有同样的余数的点对有几个
// 这里就可以使用哈希表，每考察一个点，我们就把当前点的余数存入哈希表中
// 后续遇到可以直接查阅哈希表，就知道在这个数之前有多少个数与当前数有同样的余数，有多少个余数就有多少个点对
// 因此得解
const int N = 100010;

long long int s[N];
int Hash[N];
long long int res = 0;
int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}

	//处理哈希表
	Hash[0] ++;
	for (int i = 1; i <= n; i++)
	{
		res += Hash[s[i] % k];
		++Hash[s[i] % k];
	}

	cout << res;
	return 0;
}