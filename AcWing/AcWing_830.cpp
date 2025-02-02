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

//输出左边第一个比它小的数字 这道题的核心就在于 我们站在第i个数字 往前看 所有在i之前 比a[i]大的数字 是绝对不可能在之后被用到的
// 这个用反证法可以证明 因此基于这一点 我们每一次维护一个栈，指针读到一个新的数字 就去查看栈顶的元素，弹出所有比i大的数字，然后把i入栈
const int N = 100010;
int w[N];
int res[N];


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];

	int l = 0; // 指针
	stack<int> s; // 栈顶维护
	while (l < n)
	{
		int t = w[l]; // 拿到目前读入的数字 站在这个数字往前看堆栈
		while (!s.empty() && s.top() >= t) s.pop(); // 一直搜索这个堆栈，直到堆栈为空 或者 栈顶元素比  t小
		if (s.empty()) res[l] = -1; // 从上一个循环出来只有两种可能， 分别处理这两种可能
		else res[l] = s.top();
		s.push(t); // 别忘了把目前站在的这个数压入栈中
		l++;
	}
	for (int i = 0; i < n; i++) cout << res[i] << " ";


	return 0;
}