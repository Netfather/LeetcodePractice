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

// 首先对于任意一个数字，挨个求他的二进制位数 只需要把这个数字右移就可以了
// 然后判断这一位的末尾是否是1 只需要把数字 和1 做一个取就可以了
const int N = 100010;
int w[N];

int main()
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++)
	{
		// 方法一 本质公式位 num  >> k  & 1
		//int res = 0;
		//int num = w[i];
		//while (num)
		//{
		//	if (num & 1) res++;
		//	num = num >> 1;
		//}
		//cout << res << " ";
		// 方法二  使用lowbit公式，x&(-x)这个公式会返回x 每次lowbit操作截取一个数字最后一个1后面的所有位，
		//每次减去lowbit得到的数字，直到数字减到0，就得到了最终1的个数，
		int res = 0;
		int num = w[i];
		int tmp = num;
		while (tmp)
		{
			res++;
			tmp = tmp - (tmp & (-tmp));
		}
		cout << res << " ";

	}

	return 0;
}