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

//首先遍历一遍数据  我们可以在O(n)时间内得到 待填入的位置 以及 需要填入的数字  以及填入的全排列不能等于的位置
// 那么 这个问题就退化为  给定两个 顺序排列的 序列  a1 a2 a3 ... an  和 b1 b2 b3 .. bn
// 请问如何操作an序列才能使得 对于所有的 1到n   ai不等于 bi恒成立
// 由于数据保证 有解  那么我们只需要  遍历2到n的位置 一旦该位置等于 bn 我们就把该位置和前面的数字swap一下 


// 修订 最后我们再来处理一下第一个尾巴 如果相等 我们就把第一个数字和第二个数字交换一下 
// 由于题目是保证一定有解的 因此这种方法一定可以求得最终的结果
//就一定可以在O(n)的时间内得出序列

vector<int> unequal; //不能等于数组   这个数组按顺序存放着  0位置的  下标索引
vector<int> number; // 填入数字数组  这个数组存放着 需要填入的数据
const int N = 200010;
int a[N]; //存储原始数据
bool Table[N]; //用于记录数据中哪些未填写


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		//清空一下 Table
		memset(Table, false, sizeof Table);

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0) unequal.push_back(i);
			else Table[a[i]] = true; //如果不为0 就把这个数的标志位置为1
		}
		for (int i = 1; i <= n; i++) 
			if (!Table[i]) number.push_back(i);
		sort(number.begin(), number.end());  //给需要填入的数据排个序
		// 到这一步 unequal存放着 bn    number中存放着 an  同时两个都是升序数组
		// 我们需要操作 an 使得对于所有的1到n  都有 an不等于 bn恒成立
		// 根据升序数组的特性 我们可以通过交换的方式 在O(n)时间内巧妙地构造出满足题意的an排列

		//如果相等 说明需要交换位置  
		for (int i = 1; i < unequal.size(); i++)
			if (number[i] == unequal[i]) swap(number[i], number[i - 1]);	
		//最后， 如果第一个数字相同 则把第一个数字和第二个数字交换一下 由于 数据保证了一定有解 因此这种方式一定可以构造出满足题意的排列
		if (number[0] == unequal[0]) swap(number[0], number[1]);

		//输出结果
		for (int i = 1, j = 0; i <= n; i++)
		{
			if (a[i] != 0) cout << a[i] << " ";
			else cout << number[j++] << " ";
		}
		cout << endl;
		//清空数组
		unequal.clear();
		number.clear();
	}
	return 0;
}