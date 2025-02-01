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

//前缀和思想  由于 1 和 -1 相乘一直是本身 因此用1 和-1 来指代数据的正负  然后预处理一个前缀数组即可
// 同时注意到 由于  正负逆序对的总和一定是固定的 （排列组合问题） 因此两个结果相加必定等于  n * (n-1) / 2 + n
// 很遗憾会超时 因此这里还有一些更细致的优化部分
//const int N = 200010;
//int w[N];
//int s[N];
//
//int main()
//{
//	int n;
//	cin >> n;
//	s[0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i];
//		if (w[i] > 0) s[i] = s[i - 1];
//		else s[i] = (-s[i - 1]);
//	}
//	//遍历所有询问
//	long long res_pos = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			if (s[i] / s[j - 1] > 0) res_pos++;
//		}
//	}
//	cout << n * (n - 1) / 2 + n - res_pos << " " << res_pos << endl;
//	return 0;
//}

// 2O(n)方法 维护两个数组分别是  po[N] ne[N] .表示以i个元素结尾的正负元素对的个数
// 那么根据dp分析法 我们可以i得到一个递推式  每次查看读入的数字，如果为正 ，则pon = po n-1  + 1 这里的1是需要算上读入的这个数自己
const int N = 200010;
int w[N];
int po[N];
int ne[N];

int main()
{
	int n;
	cin >> n;
	cin >> w[0];
	//初始化
	if (w[0] > 0) po[0] = 1, ne[0] = 0;
	else po[0] = 0, ne[0] = 1;
	unsigned long long res1 = ne[0], res2 = po[0];

	for (int i = 1; i < n; i++)
	{
		cin >> w[i];
		if (w[i] > 0)
		{
			po[i] = po[i - 1] + 1 , ne[i] = ne[i - 1];
		}
		else
		{
			po[i] = ne[i - 1] , ne[i] = po[i - 1]  + 1;
		}
		res1 += ne[i];
		res2 += po[i];
	}
	cout << res1 << " " << res2 << endl;
	return 0;
}