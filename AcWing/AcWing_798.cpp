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

const int N = 1010;
int w[N][N];
int b[N][N]; // 存储差分矩阵 第ij的位置表示  从b00 到 bij的矩形的和 = wij


// 这时候就要考虑如何将一个数字插入到差分矩阵中了
// 当在w的 x1,y1 x2,y2之间 包括两个端点 中所有数加上C的时候 差分 矩阵的变化
// 直接考虑很难考虑，这里是站在差分矩阵b的角度， 来解读原矩阵w的变化
// 如果我们给差分矩阵某个点+c 那么反映在原矩阵中 从这个点开始到右下角所有元素全部+c
// 用这种方式可以很方便的变化差分矩阵来使得 原矩阵某个范围的元素+c
void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y2 + 1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
}


int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> w[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			insert(i, j, i, j, w[i][j]);
		}
	}

	while (q--)
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  // 简单的二维求前缀和 看不懂这里可以先看二维前缀和的那道题

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (j == m) printf("%d\n", b[i][j]);
			else printf("%d ", b[i][j]);


	return 0;
}