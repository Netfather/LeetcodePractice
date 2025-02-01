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

// 如果不删除任何字符  是不可能的，因为我们一定可以通过删除最后一个字符 使得新字符串的字典序在 现有的之前
// 因此问题退化为  移除某处的字符串 使得字符串在字典序上尽可能小
// 而如果转换为进制问题 我们可以知道  在字典序上小  反映在数字实例上 就是数字的值尽可能的小。 
// 例如 由 1 2 3 4 5 构成的数字  他们构成的最小值为 12345 最大值为 54321
// 因此这道题我们只需要 枚举一遍所有的可能  保存下其中最优的那个解即可。
// 但是如上思路  无法在0(1)时间求出  删除某个字符串结点之后  剩余字符串表达的进制大小

// 因此进一步观察 我们可以发现
// 如果后一个数字比当前数字大  那么必然不可能删除当前这个数字    例如  aba 这种
// 如果后一个数字和当前数字相等 那么必然不可能删除当前这个数字   例如 aaab这种
// 如果后一个数字比当前数字小  那么就删除最靠左的这样一个数字即可  
// 为什么删除最靠左 是因为字典序的特性，越靠左的数 他在最终字典序中占据的权重就越大，因此


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		// 预处理前缀和
		string res = s;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i + 1] < s[i])
			{
				res = s.substr(0, i) + s.substr(i + 1);
				break;
			}
		}
		// 如果走完循环 res 的长度未发生变化 说明前面的n-1个数字已经是字典序中的最小值了，此时只需要直接删除最后一个数字即可
		if (res.length() == s.length()) res = s.substr(0, n - 1);
		cout << res << endl;

	}
	return 0;
}