////思路： 朴素的dp法
//
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//#include <cstring>
//#include <climits>
//using namespace std;
//
//int Solution(string a, string b,vector<int> &memo)
//{
//	if (a.empty() || b.empty()) return 0;
//	int len = a.length();
//	
//	if (memo[len - 1] != INT_MIN) return memo[len - 1];
//
//	if (a.end() == b.end()) memo[len-1] =  Solution(a.substr(0, len - 1), b.substr(0,len - 1), memo);
//	else
//	{
//		if (a[len - 2] != b[len - 2]) memo[len - 1] = Solution(a.substr(0, len - 2), b.substr(0, len - 2), memo) + 1;
//		else if (a[len - 2] == b[len - 2])
//		{
//			if (len - 3 < 0) return 0;
//			if (a[len - 3] == 'o') a[len - 3] = '*';
//			else a[len - 3] = 'o';
//			memo[len - 1] = Solution(a.substr(0, len - 2), b.substr(0, len - 2), memo) + 2;
//		}
// 	}
//	return memo[len - 1];
//}
//
//
//
//int main()
//{
//	string a, b;
//	cin >> a;
//	cin >> b;
//	int len = a.length();
//	if (len == 0) return 0;
//
//	vector<int> memo(len, INT_MIN);
//	//边界条件
//	if (a[0] == b[0]) memo[0] = 0;
//	if (a[0] != b[0]) memo[0] = 1;
//	int res = Solution(a, b, memo);
//	cout << res << endl;
//	system("PAUSE");
//	return 0;
//}