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

// 快速求出 2到1000范围内的所有质数  然后 遍历这些质数 即可
const int N = 1010;
vector<int> ZhiShu; //记录质数
int Table[N]; //记录某个数字是否为质数


int main()
{
	//在进入测试之前 先预处理一下  从2到1000的所有质数
	for(int i = 2; i <= 1000; i++)
	{
		bool is_ZhiShu = true;
		for (int j = 2; j <= int(sqrt(i)); j++) //试除法
		{
			if (i % j == 0)  //如果整除了 说明i不是质数
			{
				is_ZhiShu = false;
				break;
			}
		}
		if (is_ZhiShu)
		{
			ZhiShu.push_back(i);
			Table[i] = 1; //加入质数数字 同时Table记录
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		int n, k;
		cin >> n >> k;
		//遍历所有的可能
		for (int i = 0; i < ZhiShu.size() - 1; i++)
		{
			if (ZhiShu[i] > n) break; //当 读入的质数比限制大时 直接break
			if (ZhiShu[i] + ZhiShu[i + 1] + 1 <= n && Table[ZhiShu[i] + ZhiShu[i + 1] + 1] == 1  ) cnt++; //根据题意写定条件
		}
		if (cnt >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}