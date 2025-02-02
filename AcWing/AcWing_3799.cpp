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
//用等差数列数学推导一下可以得到
//在第i轮   dik 总计给出了x个糖果    era总计给出了y个糖果
// 当i为奇数时   x = (i+1)平方 / 4
// 当 i为偶数时   y = （2+i）*i / 4

// 所以我们只需要各自找到这两者能支付的极限  通过不等式可以得到
//  对 dik来说   i > 2根号a - 1  满足这个不等式的从小到大第一个奇数
//  对 era来说  i  > 根号(4*b + 1) - 1满足这个不等式的从小到大第一个偶数

// 由于数字过于庞大  在int中可能会有爆int风险 所以要用longlong 来存储ab 以及中间变量

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a, b;
		cin >> a >> b;
		long long res1 = 0, res2 = 0; //存储dik最高的轮数 和  ear最高的轮数
		res1 = int(2 * sqrt(a));
		if (res1 % 2 == 0) res1 = res1 + 1;
		res2 = int(sqrt(4 * b + 1));
		if (res2 % 2)res2 = res2 + 1;
		if (res1 < res2) cout << "Vladik" << endl;
		else cout << "Valera" << endl;

	}
	return 0;
}