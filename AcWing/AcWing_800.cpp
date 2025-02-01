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

const int N = 100010;
int a[N];
int b[N];

// 这道题思路的关键就在于 首先移动l 直到满足 A + B  > x
// 然后再移动r 直到满足 A+ B < x
// 如果中间有 == 就直接输出即可
// 因为题目保证有唯一解， 所以在这个基础上我们可以通过反证法证明，通过这个方法 一定可以找到唯一的那组解使得满足题意
// 换而言之就是 在b上的指针 绝对不会往后退，否则唯一性遭到破坏
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int l = 0, r = m - 1;
	while (l < n)
	{
		while (a[l] + b[r] < x) l++;
		while ((r >= 0) && (a[l] + b[r] > x)) r--;
		if (a[l] + b[r] == x)
		{
			cout << l << " " << r << endl;
			break;
		}
	}
	return 0;
}