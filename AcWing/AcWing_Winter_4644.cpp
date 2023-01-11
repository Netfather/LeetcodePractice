//思路：
// 前缀和题

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

const int N = 200010;
int w[N];
typedef long long LL;
LL res = 0;
LL s[N];

int main()
{
	int n;
	cin >> n;
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		res += w[i] * (s[n] - s[i]);
	}
	cout << res << endl;


	return 0;
}