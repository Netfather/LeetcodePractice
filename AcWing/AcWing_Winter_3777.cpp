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

// 观察翻牌操作的特性 我们可以总结出一下规律
// 最核心的特性是  翻牌操作一定可以将字符串分为 前全为B  后面全为W的情况
// 这个特性可以通过反证法证明 如果在全为B的前面  有一个孤立的W  那么我们可以通过翻牌将 BWB 改为  BBW 这样就实现了一次W的后移

// 因此 我们可以直接在读入一个数据之后 马上判断出 此字符串是否有解  解答的充分必要条件就是 B的数量为偶数个或W的数量为偶数个
// 接下来考虑操作数
// 一旦我们能够判断这个过程是否有解 以及 到底修改哪个我们就能直接使用递推来落实具体操作
// 递推过程如下  遍历一遍s 一旦当前指针的 颜色是需要改变的颜色 直接改变 同时将操作的坐标 纳入Operation 数组即可
//

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		int cnt_B = 0; //统计B出现了几次
		int cnt_W = 0; //统计W出现了几次
		bool Change_B = false; //true表示 此S通过修改B为W 
		bool Change_W = false; //true表示 此s通过修改 W 最终结果是全B的
		vector<int> Operation; //记录修改的坐标点
		
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'B') cnt_B++;
			else cnt_W++;
		}
		
		//避免出现纯W 或者 纯B的情况
		if (cnt_B == n || cnt_W == n)
		{
			cout << 0 << endl;
			continue;
		}

		if ((cnt_B % 2 == 0) && (cnt_W % 2 == 1)) Change_B = true;   // B的数量为偶数个 说明要改B
		else if ((cnt_B % 2 == 1) && (cnt_W % 2 == 0)) Change_W = true; // W的数量为偶数个 说明要改W
		else if ((cnt_B % 2 == 0) && (cnt_W % 2 == 0)) //如果都为偶数个 我们就取其中最小的那个进行修改
		{
			if (cnt_B < cnt_W) Change_B = true;
			else Change_W = true;
		}

		if (!Change_B && !Change_W) cout << -1 << endl;  //如果都为奇数 那么直接返回 -1 说明无解
		else {
			for (int i = 0; i < n - 1; i++)
			{
				if (Change_B && s[i] == 'B')
				{
					Operation.push_back(i + 1);
					s[i] = 'W';
					if (s[i + 1] == 'B') s[i + 1] = 'W';
					else if (s[i + 1] == 'W') s[i + 1] = 'B';
				}
				if (Change_W && s[i] == 'W')
				{
					Operation.push_back(i + 1);
					s[i] = 'B';
					if (s[i + 1] == 'B') s[i + 1] = 'W';
					else if (s[i + 1] == 'W') s[i + 1] = 'B';
				}
			}
			cout << Operation.size() << endl;
			if (Operation.size())
			{
				for (auto key : Operation) cout << key << " ";
				cout << endl;
			}
		}

		//清理一下标志和暂存
		Operation.clear();
	}
	return 0;
}