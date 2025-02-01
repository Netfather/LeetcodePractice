/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Way1： 自顶向下的动态规划
//首先，这是一个能够将一个问题分解为子问题结构的问题
//然后，然后所有的子问题在每一种解中都存在重复结构
//对于任意 的 word1[0,1,……i……m] word2[0,1,……j……n]
//dp[i][j]只能由如下两个式子确定
//		  = dp[i-1][j-1] //if word[i] == word[j]
//        = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]) + 1 //if word[i] != word[j]
//			这部分标志这重复子问题                    这部分标志是任意删除，替换，添加操作中的任何一个
//然后自顶向下的构建这个表格即刻得到结果
int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();

	//构建dp[m+1][n+1]大小的动态规划表，多一个是为了方便计算边界条件
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
	//应当注意到边界条件在此处是针对一个字串为空，另一个字串为1的情况
	//Step1: 初始化行边界
	for (int i = 0; i < m+1; i++) dp[i][0] = i;
	//Step2: 初始化列边界
	for (int j = 0; j < n + 1; j++) dp[0][j] = j;
	//Step3: 自顶向下的生成表格
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (word1.at(i-1) == word2.at(j-1)) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
		}
	}
	return dp[m][n];
}

int main()
{
	cout << minDistance("horse", "rose") << endl;
	system("Pause");
	return 0;
}

*/