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


// 考虑一件事  即对于字符串进行一次操作 是否会导致  分数K的变化为2  答案是不会
// 因此这道题退化为 如何快速处理一个字符串的优良分数K 而操作数就是 K - target_k
int main()
{
	int t;
	cin >> t;
	for(int u = 1; u <= t; u++)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int score = 0;
		for (int i = 0; i < n / 2; i++)
		{
			if (s[i] != s[n - i - 1]) ++score;
		}
		cout << "Case #"<< u << ": ";
		cout << abs(k - score) << endl;
	}
	return 0;
}