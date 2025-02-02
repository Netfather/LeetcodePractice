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

//新的最长上升子序列的方法就不是dp问题了 而是维护一个栈
//这个栈存储的是如下的格式  索引代表 最长上升子序列的长度   对应的值 为 当前长度上升子序列的最后一个元素。
// 这种存储格式可以让我们在读入一个新的数字之后，如果数字比当前栈顶元素大 说明上升子序列的长度可以加1
// 如果比当前栈顶元素小  我们就找到他可以替换掉的元素的下界，然后替换即可。

//为了快速计算下界  避免使用二分 这里直接使用vector容器存储
int main()
{
	int n;
	cin >> n;
	vector<int> w(n, 0);
	for (int i = 0; i < n; i++) cin >> w[i];

	//维护一个堆栈
	vector<int> stk;
	// 遍历每个元素
	stk.push_back(w[0]); //压入最初始的状态 方便处理
	for (int i = 1; i < n; i++)
	{
		//如果当前数字比末尾数字大 那很好喜+1
		if (w[i] > stk.back())
			stk.push_back(w[i]);
		else
			*lower_bound(stk.begin(), stk.end(), w[i]) = w[i]; //如果比末尾数字小或等于 我们就找打当前维护堆栈对应元素的正确位置 并修改值。
	}
	cout << stk.size() << endl;
	return 0;
}