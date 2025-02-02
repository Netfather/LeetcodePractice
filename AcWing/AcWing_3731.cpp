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

//非常简单的一道题 由于n必定为偶数 这就已经是非常明显的提示了
// 说明这道题是一种对称的构造
// 例如对于 a1 a2 a3 a4  考虑b的构造为 -a4 -a3 a2 a1 这种构造显然 = 0 恒成立
// 的解
const int N = 110;
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = n; i > n / 2; i--) cout << -a[i] << " ";
		for (int i = n / 2; i >= 1; i--) cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}