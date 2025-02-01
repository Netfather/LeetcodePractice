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

//2. 这道题的问题就在于 共边的情况
//3. 我们二进制枚举一下所有可能的共边情况，共边意味着对应的URDL要减去相应的值
//4. 在减去相应的值后 只要保证新边必定在 0 到 n-2 之间就意味着必定有解 

//4. 由于只有4个格子  因此我们只需要暴力枚举一下 就可以了

int st[4]; //表示 4个边界格子的染色情况

int main()
{
	int T;
	cin >> T;
Label:	while (T--)
	{
		int n, U, R, D, L;
		cin >> n >> U >> R >> D >> L;
		int u = 4;
		for (int i = 0; i < 1 << u; i++)
		{
			memset(st, 0, sizeof st);
			int U_check = U;
			int R_check = R;
			int D_check = D;
			int L_check = L;

			for (int j = 0; j < u; j++)
			{
				if (i >> j & 1) st[j] = 1;
			}
			//处理边界格子的情况
			if (st[0] == 1) U_check--, L_check--;
			if (st[1] == 1) U_check--, R_check--;
			if (st[2] == 1) R_check--, D_check--;
			if (st[3] == 1) D_check--, L_check--;
			//遍历完成之后 如果此时都大于等于0 而且小于等于n-2 说明有解
			if (U_check >= 0 && R_check >= 0 && D_check >= 0 && L_check >= 0
				&& U_check <= n - 2 && R_check <= n - 2 && D_check <= n - 2 && L_check <= n - 2	)
			{
				cout << "YES" << endl;
				goto Label;
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}