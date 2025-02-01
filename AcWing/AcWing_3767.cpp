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

//非常简单的一道题，首先如果我们要让 a尽可能多的远离b，同时还要保证 max pi尽可能的小
// 那么只有一种情况 那就是  pi中所有的数字都是相等的 且 pi只有在 ai= 1的位置才会取到值
// 在这种情况下  当ai = bi pi的多少不会对不等式造成任何影响
// 而 ai = 1 bi = 0的时候 此不等式会加速成立。

// 因此这道题退化为   统计一下  ai 中有多少个 只有自己为1的 次数 记为cnt_ai
// 统计一下 bi中有多少个 只有自己为1的次数 记为cnt_bi
// 最后统计一下  ai bi都为1的次数 记为cnt_both
// 寻找使得   cnt_ai * res > cnt_bi 成立的最小 整数
// 而无解只有一种情况 那就是 cnt_ai 为0 此时不论res多大 都无法使得不等式满足

const int N = 110;
int a[N], b[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	//统计
	int cnt_ai = 0, cnt_bi = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1 && b[i] != 1) cnt_ai++;
		if (a[i] != 1 && b[i] == 1) cnt_bi++;
	}
	if (cnt_ai == 0) cout << -1 << endl;
	else cout << cnt_bi / cnt_ai + 1 << endl;

	return 0;
}