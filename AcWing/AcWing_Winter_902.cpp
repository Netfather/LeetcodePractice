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

//定义 dp数组 f[i,j]表示 将子串1到i 变到1到j 需要多少操作 存储的值为  操作次数的最小值
// 下面考虑状态转移，  如果 末尾数字相等，那么 只需要考虑 f[i-1][j-1]即可
// 如果末尾不相等，那么 就需要考虑是从哪种操作转换来的
// 如果最后一步为删除操作 到达子串 1到j 那么就为  f[i-1][j] + 1
// 如果最后一步为替换操作 那么就为 f[i-1][j-1] + 1
// 如果最后一步为插入操作 那么就为 f[i][j-1] + 1

const int N = 1010;
int f[N][N];

int main()
{
	int n, m;
	string A, B;
	cin >> n >> A >> m >> B;
	//处理一下头
	A = "?" + A;
	B = "?" + B;
	memset(f, 0x3f, sizeof f); //由于是最小值 因此需要初始化为正无穷

	//初始状态 如果子串从空  变到空   此时不需要操作 因为相等 因此操作为0
	// 如果一方为空 另一方不为空 那么就是删除或者插入操作
	// 初始化
	for (int i = 1; i <= n; i++) f[i][0] = i; //从1到i的子串 删除i次 就成为空集
	for (int i = 1; i <= m; i++) f[0][i] = i; //从空集的子串 插入i次 就成为B
	f[0][0] = 0;
	//状态计算
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i] == B[j]) f[i][j] = f[i - 1][j - 1];
			else
			{
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
				f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}