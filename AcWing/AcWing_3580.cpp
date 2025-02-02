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
int w[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	sort(w, w + n);
	int res = 0;
	for (int i = n - 1; i > 0;)
	{
		if (w[i] != w[i - 1]) res += (w[i] - w[i - 1]);
		i = i - 2;
	}
	cout << res << endl;

	return 0;
}