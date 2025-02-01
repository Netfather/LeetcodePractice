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

// 这道题为 多重背包问题的二进制优化问题
// 这道题的思路和 AcWing中 3483题的思路是一样的  即 如何能够将每个物品划分为2的幂次
// 为什么划分为2的幂次 这里的原因在于
// 如果 某个物品一共有11个   我们如果不进行二进制优化打包  直接枚举 一共要枚举0到11  一共12次
// 但是如果进行二进制优化  将这个物品 重新划分为   1个物品一组为组1    1个物品2个物品一组为组2  4个物品一组为组3  4个物品为一组为组4
// 那么这个问题就退化为了01背包问题 对于所有0到11的任何数字 我们都可以只取4个组中的任意多个（但是每一组只取1次）的组合来实现
// 那么此时这个问题就退化为了 0 1 背包问题  我们需要实现一个函数 此函数能够将  vi si wi 转为 新的 01 情况下的 vi wi
const int N = 1010;
int vi[N], si[N], wi[N];
const int M = 10010;  // 
int f[M];
int vi_new[M], wi_new[M];
int tail_new = 1; //新的转换好的01 背包的末尾

// 给定一个商品的编号i  我们将这个商品转换为 对应 01 背包问题下的全新的 vi_new  wi_new
void Convert(int i)
{
	int num = 1; //从1个物品 划分为的 组1开始
	for (int u = 1; u <= si[i]; u++)
	{
		vi_new[tail_new] = vi[i] * num;
		wi_new[tail_new++] = wi[i] * num;
		si[i] -= num;
		if (si[i] < num * 2) break; //说明此时无法进行组2划分 直接跳出循环
		num = num * 2; // 组1划分完 开始组2划分
	}
	//如果跳出循环后还有尾数 就直接将尾数打包成一个新组
	if (si[i])
	{
		vi_new[tail_new] = vi[i] * si[i];
		wi_new[tail_new++] = wi[i] * si[i];
	}
	return;
}


int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i] >> si[i];
	}
	//将每一个物品按照拥有的个数 分组打包
	for (int i = 1; i <= n; i++) Convert(i);
	// 对  vi_new wi_new做新的 0 1背包问题动态规划
	// 由于使用二维的01背包会导致数组越界  这里要转为 1维的01背包问题解法
	// 由于什么都不选不存在价值 所以不需要对f进行初始化
	for (int i = 1; i < tail_new; i++)
	{
		for (int j = v; j >= vi_new[i]; j--)
		{
			f[j] = max(f[j - vi_new[i]] + wi_new[i], f[j]);
		}
	}

	cout << f[v] << endl;
	return 0;
}