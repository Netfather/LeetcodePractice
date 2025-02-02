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

// 由于0不是质数，因此我们只需要 考虑每一行 最多填2个 可以组合为质数的非质数  例如 1 和 4
// 然后其他部分填写0    这样就可以发现  只要每行错位 1 4 就可以实现了

// 例如对于一个 3 4 的大小 我们只需要
// 1  4 0 0
// 0  1 4 0
// 0  0 1 4
const int N = 110;
int w[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i++)
		{
			w[i][i + 0] = 1;
			if (i + 1 < n) w[i][i + 1] = 4;
			else w[i][0] = 4;
		}
		//输出样例
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << w[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}