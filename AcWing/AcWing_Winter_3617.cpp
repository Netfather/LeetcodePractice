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

//显然生成的矩形c 的行 是完全由 数组a中的数字决定的， 如果a中有一个数字为0，那么反映到对应的行 必定全是0
// 同理 列完全由 数组b中的数字决定，如果b中有一个数字为0，那么反映到对应的列 必定全是0
// 而题目需要我们找到面积为k 且只包含1的子矩形 
// 根据两个数组我们可以很快判断出哪些区域有多大的一个k,写一个函数，输入区域边长，返回这个区域的个数
// 预处理一下k 得到k的各个因式放于一个数组中,然后根据区域的大小和因数来求得对应的个数

// 思路正确 成功AC

typedef unsigned long long ULL;
const int N = 40010;
vector<int> A;  //记录a中出现的连续1的个数，将边长存储a中
vector<int> B;  // 记录b中出现的连续1的个数，将变成存储b中
vector<int> inshu;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	A.push_back(0);
	B.push_back(0);
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) ++tmp;
		else
		{
			if (tmp) A.push_back(tmp);
			tmp = 0;
		}
	}
	if (tmp) A.push_back(tmp);
	tmp = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		if (x == 1) ++tmp;
		else
		{
			if (tmp) B.push_back(tmp);
			tmp = 0;
		}
	}
	if (tmp) B.push_back(tmp);
	//不能去重 但是可以sort一下
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//预处理k 取出各个因数

	for (int i = 1; i < sqrt(k); i++)
	{
		if (k % i == 0) inshu.push_back(i);
	}
	//遍历A,B中所有的可能 这时问题演变为  由A[i] 和 B[j] 组成的区域内，可以划分出多少个k大小的子矩阵
	// Step1： 如果区域比k小 那么直接continue
	// Step2： 如果区域恰好等于k 那么res+=1
	// Step3： 如果区域比k大，那么根据k的因数分解结果，在确保边长不超过长宽的前提下  能组成的矩阵个数 = 边长 - 因数 + 1
	// 最后特判一下，因为如果可以被开根号，那么组成的k是一个矩形大小，就不需要2倍判定了
	ULL res = 0;
	ULL res_tmp = 0;
	// 暂存i j的前一个元素 进行快速计算
	for (int i = 1; i < A.size(); i ++)
	{
		for (int j = 1; j < B.size(); j++)
		{
			//判断一下 当前区域能否装下k的数
			if (A[i] * B[j] < k) continue;
			else if (A[i] * B[j] == k) res += 1;
			else
			{
				// 如果 这次的矩形和上次的矩形恰好相同，我们就直接将矩形和上次的结果记录在一起
				// 当然这个地方是可以优化的，额外维护一个表格，表格key为两个边长，value为 该区域所能抽出k大小子矩阵的个数
				if (A[i] == A[i - 1] && B[j] == B[j - 1])
				{
					res += res_tmp;
					continue;
				}

				res_tmp = 0;
				for (auto u : inshu)
				{
					if (A[i] >= u && B[j] >= k / u)
					{
						res_tmp += (A[i] - u + 1) * (B[j] - k / u + 1);
					}
					if (A[i] >= k / u && B[j] >= u)
					{
						res_tmp += (A[i] - k / u + 1) * (B[j] - u + 1);
					}
				}
				//处理一下 根号
				int x = int(sqrt(k));
				if (x * x == k)
				{
					if (A[i] >= x && B[j] >= x)
					{
						res_tmp += (A[i] - x + 1) * (B[j] - x + 1);
					}
				}
				res += res_tmp;
			}
		}
	}
	cout << res << endl;
	return 0;
}