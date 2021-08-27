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

// 非常非常简单的一道题
// 从A中挑 k个  从B中挑选m个  使得 A中调出的任意 一定小于 B中调出的任意
// 由于数组天然非降序  因此 这也就意味着  我们记从A中跳出的为 Sa  在B中调出的为 Sb
// max Sa  <   min Sb
// 而maxSa  最差最差  也必然是 A中的第k个数
// min Sb 最差最差 也必然是 B中从后往前第 m个数字
// 因此这道题得解



int main()
{
	int na, nb;
	cin >> na >> nb;
	int k, m;
	cin >> k >> m;
	int maxSa = 0, minSb = 0;
	for (int i = 1; i <= na; i++)
	{
		int tmp;
		cin >> tmp;
		if (i == k) maxSa = tmp;
	}
	for (int i = 1; i <= nb; i++)
	{
		int tmp;
		cin >> tmp;
		if (i == (nb - m + 1)) minSb = tmp;
	}
	if (maxSa < minSb) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}