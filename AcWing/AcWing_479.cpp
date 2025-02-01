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

// 首先这道题中序遍历的制约是为了确保 你可以根据根节点来成功划分两个区间
//   中序的存在，保证了根节点左右两侧是完全互不干涉的两个部分
//然后，我们就可以设定好一个dp状态 dp[i][j] 表示从i到j（包含i，j）的区间内，
//   满足题意的树的分数是多少
// 通过动态规划，我们可以很方便的得到最高分，那么如何获得这个结果的前序遍历？
// 再开一个状态 g[i][j] 这个用于记录。当找到最大值的时候，对应的根节点是谁

const int N = 35;
int dp[N][N]; //从i到j(包含i,j) 这个区间内，所能构成的所有二叉树的最高分是多少
int g[N][N]; //从i到j(包含i,j) 这个区间内，所能构成的所有二叉树的最高分对应的根节点是多少
int k[N];

void Output(int left, int right)
{
	//递归终止条件
	if (left > right) return;
	int root = g[left][right];
	cout << root << " ";
	//递归输出左子树
	Output(left, root - 1);
	Output(root + 1, right);
	return;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> k[i];

	//区间遍历 先枚举长度，然后枚举左端点
	for (int len = 1; len <= n; len++)
	{ 
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1; //计算得到右端点
			//if (len == 1) dp[i][j] = 1; // 如果某一个子树为空，那么规定加分为1
			if (len == 1) dp[i][j] = k[i], g[i][j] = i; // 如果长度为1 意味着这个区间只包含自身，那么根据题意，只包含自己的叶子结点只需要考虑自己
			else
			{
				for (int root = i; root <= j; root++) //开始枚举根节点
				{
					//先计算从i到root-1区间的最大值
					int left;
					if (root == i) left = 1;
					else left = dp[i][root - 1];
					//再计算从root+1到j区间的最大值
					int right;
					if (root == j) right = 1;
					else right = dp[root + 1][j];
					//计算当前这个地方的得分是否比原来的大，如果是，就更新结果
					int score = left * right + k[root];
					if (score > dp[i][j])
					{
						dp[i][j] = score;
						g[i][j] = root;
					}
				}
			}
		}
	}

	cout << dp[1][n] << endl;
	Output(1, n);
	cout << endl;

	return 0;
}