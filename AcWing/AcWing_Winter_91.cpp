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

//状态压缩问题  + 二进制枚举问题
// 考虑这样一种二进制  二进制为 n位，第i位的0代表 不包括第i个点  第i位的1代表包括第i个点
// 考虑f[state][j] 表示 state中记录了当前已经走过了多少个点，而且最后停在第j个点的所有可能路径方案数
// 属性存储的是方案的最小值
// 考虑状态转移，则考虑state中所有已经为1的位，枚举除掉该位得到状态k，然后f[state_k][u] + w[u][j] 为可能的候选项
// 对所有候选项求个min即可

const int N = 21, M = 1 << N;
int f[M][N];//dp
int g[N][N]; // 存储所有的边权

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	//状态初始化
	memset(f, 0x3f, sizeof f);
	// 状态为0表示集合中根本没有点 这时候不存在距离 为正无穷
	// 当状态为1时 表示集合中只有0号顶点，这时候为起点位置   除此以外的所有位置 都是正无穷
	f[1][0] = 0; //起点位置没有距离 为0

	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//枚举所有状态  对所有为1的位置进行处理
			if (i >> j & 1)
			{
				// f[i][j]
				//1. 计算除掉当前j的新状态 
				// 新状态为  i - (1 << j)
				//2. 查看新状态 哪些位为1
				for (int k = 0; k < n; k++)
				{
					if ((i - (1 << j)) >> k & 1)
						f[i][j] = min(f[i - (1 << j)][k] + g[k][j], f[i][j]);
				}
			}
		}
	}
	//结果为 当状态全部为1 并且走到了 n-1号端点的值
	cout << f[(1 << n) - 1][n - 1] << endl;

	return 0;
}