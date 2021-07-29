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

//本质是求约数问题   给定 一个整数n 找到n的所有约数
typedef long long LL;

int main()
{
	LL n, k;
	cin >> n >> k;
	vector<LL> Yueshu;

	for (int i = 1; i <= int(sqrt(n)); i++)
	{
		if (n % i == 0)
		{
			Yueshu.push_back(i);
			if (n / i != i) Yueshu.push_back(n / i); //得到的除数也是约数之一
		}
	}
	sort(Yueshu.begin(), Yueshu.end());
	if (k <= Yueshu.size()) cout << Yueshu[k - 1] << endl;
	else cout << -1 << endl;
	return 0;
}