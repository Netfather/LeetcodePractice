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

const double PI = 3.1415926535897932; // 定义圆周率
const int N = 110;
int w[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	sort(w, w + n);
	double res = 0;
	//判断奇数
	int i = 0;
	if (n % 2) res = w[0] * w[0], i = 1;
	//遍历所有边长
	for (; i < n - 1;)
	{
		res += w[i + 1] * w[i + 1] - w[i] * w[i];
		i = i + 2;
	}
	printf("%6f", res * PI);
	return 0;
}