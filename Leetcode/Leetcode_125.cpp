//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//bool checksignle(char s)
//{
//	if (s >= 65 && s <= 90 ||   //A~Z
//		s >= 97 && s <= 122 ||  //a~z
//		s >= 48 && s < 58  // 0 ~ 9
//		) return true;
//	return false;
//}
//
//bool isPalindrome(string s) {
//	if (s.empty()) return true;
//	int start = 0;
//	int end = s.length()-1;
//	while (start < s.length())
//	{
//		if (!checksignle(s[start]))
//		{
//			++start;
//			continue;
//		}
//		if (!checksignle(s[end]))
//		{
//			--end;
//			continue;
//		}
//		if (s[start] == s[end] || 
//			s[start] >= 65 && s[start] <= 90 && s[start] + 32 == s[end] ||
//			s[start] >= 97 && s[start] <= 122 && s[start] - 32 == s[end])
//		{
//			++start;
//			--end;
//			continue;
//		}
//		else return false;
//	}
//	return true;
//}
//
//
//int main()
//{
//	string s = "P0";
//	cout <<isPalindrome(s) <<endl;
//	system("Pause");
//	return 0;
//
//}