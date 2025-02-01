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

//const int V = 25;
//int Bi[V];
//int cnt = 0;
//long long sum = 0;
//
////此法雖然結果正確 但是超時
////使用暴力搜索是不適合的。
//void dfs(int target,int v,int start)
//{
//	//终止条件判断区
//	if (sum >= target)
//	{
//		if (sum == target) cnt++;
//		return;
//	}
//
//	for (int i = start; i < v; i++)
//	{
//		if (sum + Bi[i] <= target)
//		{
//			sum += Bi[i];
//			dfs(target, v, i);
//			sum -= Bi[i]; //恢复现场
//		}
//		else return;
//	}
//}

//使用dp來解題
const int V = 30;
const int N = 10010;

long long dp[V][N];
//這個dp表示 從1到第i個貨幣，任意選擇使得加和為N的方案有多少種？

int main()
{
	int v,n;
	cin >> v >> n;
	dp[0][0] = 1;//這一種方案表示什麼都不選
	for (int i = 1; i <= v; i++)
	{
		int v;
		cin >> v;
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j]; //先把不包括當前輸入的數據，使得加和為j的數據加入
			//然後判斷，如果當前輸入的數據比j小，說明當前的數據可以累加，此時再算上本次的加和
			if (j >= v) dp[i][j] += dp[i][j - v];
		}
	}
	cout << dp[v][n] << endl;
	return 0;
}