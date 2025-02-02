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

// 我们可以任意举一个例子 就知道如何构造了 例如我们要构造一个 10长度的字符串
// 假定 第一第二位已经确定是  ab 那么为了避免出现长度为3的回文 我们只能如下构造
//  abbaabbaabb 这样
// 如果第一第二为是 bb 或者 aa 那么直接重复即可
// 因此构造方式就很明确了


//构造方式正确 但是超时了，  那就直接输出就好了 根据输出的位数来控制当前输出哪个数字
int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (((i + 1) / 2) % 2 != 0) cout << "a";
		else cout << "b";
 	}
	return 0;
}