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

//字符串哈希是非常非常强大一个方法 虽然有可能失效 但是从理论上失效的概率很低
// 实现此方法的关键在于两个数组一个  h  一个p
// h用于存储前 多少个 字符串他的哈希值
// p用于存储前 计算 l r 区间长度时候的哈希值    同时为了避免mod  直接开一个 ULL 即可
// 一般哈希方法是 将字符串视为一个p进制的数字 然后最后mod 一个 2的64次方
typedef unsigned long long ULL;
const int N = 1000010;
int P = 13331;
ULL h[N];
ULL p[N];   // 这个是进制存储器 用于存储第k位的p进制  反映到十进制是多大的数字(只有第k位位1 其他位都是0)

// 查询函数  输入 左右两边端点 
ULL query(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	int n, m;
	string a;
	cin >> n >> m;
	cin >> a;
	a = "?" + a;


	p[0] = 1;  // 因为此时值为1
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + a[i];
	}

	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if (query(l1, r1) == query(l2, r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}