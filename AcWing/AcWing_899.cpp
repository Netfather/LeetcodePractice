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

// 由于长度不会超过10 因此就是通过最短编辑距离来判断 是否能在指定次数内达到目标字符串
// 考虑如下的dp分析过程
// f[i][j] 表示 从 1-i 变化到 1-j的所有变化可能性    属性存储的是 变化的次数最小值
// 考虑状态转移
// 如果最后一个数字相同  那么就是 f[i-1][j-1]
// 如果最后一个数字不相同   1. 考虑插入 那么就是 f[i][j-1] + 1 
// 2. 考虑替换  那么就是 f[i-1][j-1] + 1
// 3. 考虑删除 那么就是 f[i-1][j] + 1
const int N = 1010;
int f[15][15];
string str[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];
	while (m--)
	{
		string b;
		int cnt;
		cin >> b >> cnt;
		b = "?" + b;
		// 初始化 f
		memset(f, 0x3f, sizeof f);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			string a = str[i];
			a = "?" + a;
			for (int i = 0; i <= b.length(); i++) f[0][i] = i; //插入i次
			for (int i = 0; i <= a.length(); i++) f[i][0] = i; //删除i次
			for (int i = 1; i <= a.length(); i++)
			{
				for (int j = 1; j <= b.length(); j++)
				{
					if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
					else
					{
						f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
						f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
					}
				}
			}
			if (f[a.length()][b.length()] <= cnt) res++;
		}
		cout << res << endl;
	}
	return 0;
}
