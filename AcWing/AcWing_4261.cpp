//思路：
/*
每个连续不少于三头奶牛的序列拍照  意味每次拍照大于等于3
且题目表明如果两张照片以不同位置的奶牛开始结束，认为他们是不同的
说明 这道题就是要暴力枚举所有的可能性
因此思路如下
从3开始 从第一个元素开始枚举所有的可能性，如果区间内只有一头单一品种的牛，则计数器+1

使用前缀依然会TLE 因为数据范围过大

这里得考虑从结果出发  我们首先找到序列中符合孤独条件的位置
然后从那个位置出发 统计所有包含该位置的 能够挑选出来的所有子序列的数量即可

*/
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

const int N = 500010;
int s[N];
string cow;
typedef long long LL;
LL res = 0;
LL max(LL a, LL b) {
	return a > b ? a : b;
}
//TLE版本
//int main()
//{
//	int n;
//	cin >> n >> cow;
//// 预处理一个前缀数组
//	s[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (cow[i - 1] == 'H') s[i] = s[i - 1] + 1;
//		else s[i] = s[i - 1] + 0;
//	}
//// 开始枚举
//	int window = 3;
//	while (window <= n)
//	{
//		for (int i = 1; i <= n - window + 1; i++) if (s[i + window - 1] - s[i-1] == 1 || s[i + window - 1] - s[i-1] == window - 1) res++;
//		window++;
//	}
//	cout << res << endl;
//
//	return 0;
//}

int main()
{
	int n;
	cin >> n >> cow;
	for (int i = 0; i < n; i++)
	{
		LL l = i, r = i;
		LL range_l = 0, rang_r = 0;
		while (l > 0 && cow[--l] != cow[i]) range_l++; // 往左边走 找到第一个与当前点一样的位置
		while (r < n - 1 && cow[++r] != cow[i]) rang_r++; // 往右边走 找到第一个与当前点一样的位置
		res += range_l * rang_r + max(0, rang_r - 1) + max(0, range_l - 1); // max是为了防止出现 rang_l 和 rang_r同时为0的情况
		// 同时注意到  序列宽度应当是小于3的 所以这里 rang_r 和 rang_l需要减1
	}
	cout << res << endl;
	return 0;
}