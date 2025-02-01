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

const int N = 30010;
const int M = 30;

int dp[M][N]; //dp含义，再1到M个物品中选，使得题目规定的总分不超过N的情况
//我们将问题划分成两个部分，是否选择第i个物品
// 如果不选择第i个物品 那么恰好是dp[i-1][N]
// 如果选择第i个物品，那么在保持i不东的情况下，找到1到i-1中 总价值不超过N-value[i]的情况
// 注意这里注意辨析，N表示的是物品的价格，也就是我们统计的是物品价格不超过的大条件下，
// 而dp中存储的是总分，这种问题一般存在三个维度 第一维度为物品本身，第二维度为物品的价值，体积，等大的制约，第三维度为根据重要度或者其他因此赋予了物品的权值
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int value, weight;
		cin >> value >> weight; //读入价值和重要度权重
		int sum = value * weight; //根据题意，总的价值度总和为二者相乘

		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - value >= 0) dp[i][j] = max(dp[i][j], sum + dp[i - 1][j - value]); // 因此在这里，和dp相加的是sum 也就是题目赋予的权值

		}
	}
	cout << dp[m][n];
	return 0;
}