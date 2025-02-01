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

//首先明确  奇数乘奇数 必定为奇数   其余的必定为偶数
// 然后  偶数+偶数  为偶数   奇数+奇数为偶数  奇数+偶数为奇数  这是一个异或操作
// 因此这道题就是再度如ak的时候  就判断出该项是奇数还是偶数   然后把对应的数字做一个异或
//时间复杂度为 10的6次方 可以过
const int N = 100010;
int a[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int b, k;
		cin >> b >> k;
		for (int i = 1; i <= k; i++) cin >> a[i];
		//根据奇偶相乘性质 判断每一项是奇数还是偶数
		for (int i = 1; i < k; i++)
		{
			if (b % 2 == 1 && a[i] % 2 == 1) a[i] = 0;
			else a[i] = 1;
		}
		//处理一下尾巴
		if (a[k] % 2 == 1) a[k] = 0;
		else a[k] = 1;
		// 根据同或操作 从左到右判断结果的奇偶性质
		int res = a[1];
		for (int i = 2; i <= k; i++) res = !(res ^ a[i]);
		// 根据res 的 0 1 输出结果
		if (res == 0) cout << "odd" << endl;
		else cout << "even " << endl;

	}
	return 0;
}