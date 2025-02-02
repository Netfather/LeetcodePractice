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

//分组背包问题 
const int N = 110;
int f[N][N];
int vi[N][N]; // 表示第i组 第j个物品的体积
int si[N]; //表示第i组物品有多少个
int wi[N][N]; //表示第i组 第j个物品的价值

int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> si[i];
		for (int j = 1; j <= si[i]; j++) cin >> vi[i][j] >> wi[i][j];
	}
	//考虑边界情况 当从第0组选 此时的价值自然为0 因此不需要初始化
	for (int i = 1; i <= n; i++) //从第i组物品选
	{
		for (int j = 0; j <= v; j++) // 总体积不超过j
		{
			//不选第i组物品中的任何一个
			f[i][j] = max(f[i][j], f[i - 1][j]);
			// 选第i组物品 的第k个
			for (int k = 1; k <= si[i]; k++)
			{
				if(j >= vi[i][k]) f[i][j] = max(f[i][j], f[i - 1][j - vi[i][k]] + wi[i][k]);
			}
		}
	}
	cout << f[n][v] << endl;
	return 0;
}