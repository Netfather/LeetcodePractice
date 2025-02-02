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

//
//2. 
//3.
//4. 注意到 一旦存在不能整除的 就会马上停止遍历  但是纯粹的模拟过程 必定会超时
//5. 注意到  延展的数是 x个 w/x 也就是只要能延展 那必定是延展w[i]的大小
// 因此考虑如下过程 用w维护每次除以x之后的商，用org_w维护最开始输入的结果，每次从头开始遍历，迭代w，如果能整除w 就更新w 然后结果加上org_w即可
typedef unsigned long long ULL;
const int N = 100010;
int w[N];
int org_w[N];


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		ULL res = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			org_w[i] = w[i];
			res += w[i];
		}
		int flag = 0;
		while (1)
		{
			for (int i = 0; i < n; i++)
			{
				if (w[i] % x != 0)
				{
					flag = 1;
					break;
				}
				res += org_w[i];
				w[i] = w[i] / x;
			}
			if (flag) break;
		}
		cout << res << endl;
	}
	return 0;
}