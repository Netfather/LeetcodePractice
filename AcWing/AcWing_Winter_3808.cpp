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

// 尽可能将着n个正方形组织成  一个大正方形的形式
// 约定  (k-1)平方  < n < k平方
// 如果n恰好等于某个k的平方的时候  结果必定是 2k
// 如果不等于k的平方  结果必定是  k +  n % (k)   结果多不多加1 取决于 能否被除尽 是否有尾巴

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int k_l = int(sqrt(n));
		if (k_l * k_l == n)
		{
			cout << 2 * k_l << endl;
			continue;
		}
		int k_r = k_l + 1;
		if (n % k_r) cout << (k_r)+n / (k_r)+1 << endl;
		else cout << (k_r)+n / (k_r) << endl;
	}
	return 0;
}