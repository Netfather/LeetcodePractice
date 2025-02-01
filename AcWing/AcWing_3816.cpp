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

// 首先问题可以退化为  移动其中一个元素， 使得在移动操作完成之后， 数组的前半部分之和 为某个固定值x
// 然后我们可以发现  这种操作 不会影响数组的整体连续性， 
// 因此 按照如下方式可以在O(n)时间内进行搜索
// 在读入的时候，我们找到某个位置k 使得  a1+ a2+a3+ ak-1 < x    此时如果等于x则直接输出Yes
// a1 + a2 +a3 + ak + ak > x
//此时分情况讨论 1. 如果我们移动的是1到k之间的数字，那么自然破坏了连续性，但是由于只能一次移动一个  所以 后面的部分就不能动了
//					而此时不动的情况已经排除，只能将这个数字移动到后半部分，那么此时我们需要将这个数字删去 然后把数组往后延申，找到
//					是否有满足的  没有就直接break
// 2. 如果移动的是 k+1到 n的数字，那么我们只需要直接寻找  是否有某个数字恰好等于 x - a1-a2 -ak  有的话就输出Yes 没有就No
// 其中情况2的复杂度为0(1) 情况1的复杂度最坏为 O(n - k) 因此是可以过的
typedef unsigned long long LL;

const int N = 100010;
LL w[N];
LL s[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		unordered_set<LL> Table; //用于存储某个数字是否出现过  这里只存储 后半部分的数字
		int n;
		cin >> n;
		LL tmp_cnt = 0; //用于寻找指定的k位置
		//读入数据 同时预处理前缀和数组
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			s[i] = s[i - 1] + w[i];
		}
		//计算目标值  如果和为奇数 说明不可能存在
		if ((s[n] - s[0]) % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		LL x = (s[n] - s[0]) / 2; //获得目标值x
		int k = -1;
		// 遍历一遍找到关键位置k 同时将k+1 之后的所有数字全部入哈希表
		for (int i = 1; i <= n; i++)
		{
			tmp_cnt += w[i];
			if (tmp_cnt == x)
			{
				cout << "YES" << endl;
				break;
			}
			else if (tmp_cnt > x && k == -1)
			{
				k = i - 1; 
			}
			
			if (k != -1) Table.insert(w[i]);
			
		}
		if (tmp_cnt == x) continue;

		//分情况讨论  先考察从k+1到n之间的数字
		// 
		bool ans = false;
		for (int i = 1; i <= k; i++)
		{
			if (Table.count(x - (s[i] - s[0])))
			{
				ans = true;
				cout << "YES" << endl;
				break;
			}
		}
		if (ans == true) continue;
		//分情况讨论  再考察从1到k之间的数字
		k++; //这里++的目的是把 k的位置 置于  第一次 >x的位置，因为是替换之前的数字，因此边界是需要保留的
		// 这里可以通过很多样例来 证明 例如  大小为6  顺序为 5 4 1 2 2 2 的序列，如果k = 1是没有解的 但其实我们只需要把 4挪动到后面去就行了
		for (int i = 1; i <= k; i++)
		{
			LL tmp = s[k] - s[0] - w[i];
			if (tmp == x)
			{
				cout << "YES" << endl;
				ans = true;
				break;
			}
			for (int j = k + 1; j <= n; j++)
			{
				tmp += w[j];
				if (tmp == x)
				{
					cout << "YES" << endl;
					ans = true;
					break;
				}
				else if (tmp > x)
				{
					ans = false;
					break;
				}
			}
			if (ans == true) break;
		}
		//到这里还不是true只能是No了
		if (ans == false) cout << "NO" << endl;

		Table.clear();  
	}
	return 0;
}