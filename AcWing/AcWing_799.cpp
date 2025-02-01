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



//双指针做法  
//const int N = 100010;
//int w[N];
//int Table[100000]; //用于记录 每个出现的数字 在w中的下标索引地址
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	int res = INT_MIN;
//	// 双指针 维护一段区间
//	int l = 1, r = 1;
//	while (r != n + 1)
//	{
//		// 每当r前进一位， 如果读入的数据不存在于Table中 那么就继续读入
//		// 如果对应的坐标已经存在 那么
//		if (Table[w[r]] != 0)
//		{
//			res = max(res, r - 1 - l + 1);
//			// 修改l到新的坐标  注意这里要修改的话需要把到目标位置之前所有记录在Table中的数字清空
//			while (l < Table[w[r]] + 1) Table[w[l++]] = 0;
//		}
//		Table[w[r]] = r;
//		r++;
//	}
//	res = max(res, r - 1 - l + 1);
//	cout << res << endl;
//	return 0;
//}


//注 此法和标准答案解法是差不多的意思，同样是用Table记录存在的次数，但是更加简练一些
const int N = 100010;
int w[N];
int Table[N]; //存储之前所有元素出现的个数

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	//双指针， 右指针不断向前探，左指针维护能够维持右指针最大不重复的下标索引
	int l = 1, r = 1;
	int res = INT_MIN;
	while (r < n + 1)
	{
		// 每读入一个数 我们就直接对Table++
		++Table[w[r]];
		// 判断这时候Table的次数有没有大于2
		while (Table[w[r]] > 1) --Table[w[l++]]; //一旦确认有大于2的存在，左端点开始行动，一路找，直到找到使得Table > 1的罪魁祸首
		res = max(res, r - l + 1 );
	}
	res = max(res, r - l );
	cout << res << endl;
	return 0;
}