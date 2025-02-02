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

// 典中典之爆炸螺旋难上天的一道题
// 首先关于状态压缩dp，我们需要明白 状态压缩之所以叫状态压缩，是把某种状态用一个数来表示
// 例如这道题，我们将某一列多伸出来的一小格作为1，没有伸出来作为0， 用二进制构成一个状态，
// 这道题的 dp状态是固定的，f[i][j] 表示  前i-1列已经完全填好，然后看第i列，伸出来的小格子状态为j的所有方案数量
// 考虑状态计算， 那么 所有合法的能够从 f[i-1][k] 走到  f[i][j] 就为目标所求
// 因此这道题需要考虑的就是  当i-2行已经完全排列好，伸出的小格子状态为k  是如何   转移到 i-1行已经完全排列好，并且伸出的小格子状态为j

// 那么随便模拟几种情况我们可以明白
// 1.如果k状态中伸出小格子，那么 j状态必然不可能伸出小格子，否则就会有格子非法摆放了  即 i& j == 0
// 2.如果k状态中有地方没有伸出小格子，而j状态也没有伸出小格子，意味着此时只能摆放竖着的小格子
//				那么这些地方在纵向上的数量必须是偶数，否则也是非法的。

// 综上，我们需要 首先预处理一下所有可能的状态，判断连续0的个数是否为偶数
// 然后我们还需要对每个j 处理一下 哪些k能够合法的走到j状态上来
const int N = 12, M = 1 << N; // 枚举一下棋盘的长宽，以及所有的状态数
long long f[N][M];
bool st[M]; //用于预处理  连续0的个数是否为偶数
vector<int> state[M]; // 用于记录哪些k能够合法的走到j状态上来


int main()
{
	int n, m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		//预处理连续   使用二进制枚举的方法来得到每一位的 0 1
		// 连续0为偶数 为true 否则为false
		memset(st, false, sizeof st);
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0; //记录连续0的个数
			bool is_valid = true; //记录该数字是否合法
			for (int j = 0; j < n; j++)
			{
				//如果i右移j位为1 那么就判断一下当前cnt
				if (i >> j & 1)
				{
					if (cnt % 2)
					{
						is_valid = false;
						break;
					}
					else cnt = 0;
				}
				else cnt++;
			}
			//处理一下尾巴
			if (cnt % 2) is_valid = false;
			st[i] = is_valid;
		}

		// 预处理一下 哪种状态k能转移到状态j
		//枚举状态j
		for (int i = 0; i < 1 << n; i++)
		{
			state[i].clear();
			for (int j = 0; j < 1 << n; j++)
			{
				//当前仅当   j 和 i 不同时为1  而且  j i都为0的地方 连续0的个数为偶数 为一种合法状态
				if ((i & j) == 0 && st[i | j])
				{
					state[i].push_back(j); //说明能从状态 j 转移到状态i
				}
			}
		}

		// 处理dp
		memset(f, 0, sizeof f);
		// 初始化
		// 由于不存在-1行 因此f[0][x] 表示一个方块都不填 这也是一种方案  因此为1
		// 然后对于其他的状态 全都是非法的， 因此为0
		for (int i = 1; i < 1 << n; i++) f[0][i] = 0;
		f[0][0] = 1;
		
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 0; j < 1 << n; j++)
			{
				//遍历所有能转移到状态j的状态   
				for (auto k : state[j])
				{
					f[i][j] += f[i - 1][k];
				}
			}
		}

		cout << f[m][0] << endl;
	}
	return 0;
}