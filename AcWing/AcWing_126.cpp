//思路：

////#include <iostream>
////#include <algorithm>
////#include <set>
////#include <unordered_map>
////#include <unordered_set>
////#include <sstream>
////#include <map>
////#include <stack>
////#include <string>
////#include <vector>
////#include <queue>
////#include <list>
////#include <stdlib.h>
////#include <math.h>
////#include <cstring>
////#include <climits>
////using namespace std;
////
////一维情况，我们可以通过反证法得证明，如果读入的当前数组会使加和减小，那么就重新开始记录
////int res = INT_MIN;
////const int N = 110;
////int w[N];
////void One_dim(int n )
////{
////	int tmpres = w[1];
////	for (int i = 2; i <= n; i++)
////	{
////		if (tmpres + w[i] < tmpres)
////		{
////			//要保存当前的tmpres 然后将tmpres清空
////			res = max(res,tmpres);
////			tmpres = w[i];
////			continue;
////		}
////		tmpres += w[i];
////	}
////}
////
////const int N = 110;
////int s[N][N]; //用于存放前缀和数组
////int res;
////int main()
////{
////	我们先考虑一维的情况，当是1维的时候，我们如何获得这样一个连续的最长和子序列
////	 完成考虑一维情况之后，我们来考虑二维
////	 我们只需要考虑二维的列上的前缀和数组，然后直接当成1维度来枚举即可
////	int n;
////	cin >> n;
////	for (int i = 1; i <= n; i++)
////	{
////		for (int j = 1; j <= n; j++)
////		{
////			int tmp;
////			cin >> tmp;
////			s[i][j] = s[i-1][j] + tmp;
////		}
////	}
////
////	for (int i = 0; i <= n; i++)
////	{
////		for (int j = i + 1; j <= n; j++)
////		{
////			for (int k = 1; k <= n; k++)
////			{
////				int input = s[j][k] - s[i][k];
////				int tmpres = 0;
////				if (k == 1) tmpres = input;
////				else
////				{
////					if (tmpres + input < tmpres)
////					{
////						res = max(res, tmpres);
////						tmpres = input;
////						continue;
////					}
////					tmpres += input;
////				}
////			}
////		}
////	}
////	cout << res;
////
////
////
////	return 0;
////}