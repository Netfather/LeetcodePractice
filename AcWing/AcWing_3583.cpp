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


//首先通过反证法我们可以证明  最终的的解 必定是划分了k个组出来的
// 然后我们先把数组排序   然后按照绝对值不超过5的限制 从尾到头 划分出若干个组 数量记为S
// 最后从S中取出 前k个  容量的组即为解
const int N = 5010;
int w[N];
int s[N];
int f[N][N];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i];
	sort(w+1, w + n+1);
	//双指针预处理一下 求出最多延申到哪里
	int i= 1, j = 1;
	for (; j <= n; j++)
	{
		while ( i <= n && w[j] - w[i] > 5) i++;
		s[j] = i;
	}
	//使用dp求解
	for (int i = 1; i <= n; i++) //从1到i个元素中选
	{
		for (int j = 1; j <= k; j++) //选j组的所有方案
		{
			f[i][j] = max(f[i - 1][j], f[s[i] - 1][j - 1] + i - s[i] + 1);
		}
	}

	cout << f[n][k] << endl;
	return 0;
}