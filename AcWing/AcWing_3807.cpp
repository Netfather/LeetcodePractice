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

// 核心在于如何理解  前k个小写字母中 出现次数 最少的字母 出现的次数尽可能多

// 那么理想的理解就是  先锚定一个 出现次数最多的字母，然后让其他字母的次数 都为 m -1
// 那我们重排列以下 其实就是  把k从小到大排列 然后不断重复 直到填满s的长度即可

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		while (s.length() < n)
		{
			for (int i = 0; i < k; i++)
			{
				char word = 'a' + i;
				s += word;
				if (s.length() >= n) break;
			}
		}
		cout << s << endl;
	}


	return 0;
}