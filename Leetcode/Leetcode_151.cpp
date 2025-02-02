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
//using namespace std;


//Way1 使用stack直接弹出
//string reverseWords(string s) {
//	if (s.empty()) return s;
//	stack<string> tempres;
//	int sub_length = 0;
//	int sub_i = 0;
//	string res;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] == ' ')
//		{
//			if (sub_length != 0)
//			{
//				tempres.push(s.substr(sub_i, sub_length));
//				sub_length = 0;
//			}
//			continue;
//		}
//		else
//		{
//			if (sub_length == 0) sub_i = i;
//			++sub_length;
//		}
//	}
//	if (sub_length != 0) tempres.push(s.substr(sub_i));
//	while (!tempres.empty())
//	{
//		if(res == "") res = tempres.top();
//		else res += (" " + tempres.top());
//		tempres.pop();
//	}
//	return res;
//}



