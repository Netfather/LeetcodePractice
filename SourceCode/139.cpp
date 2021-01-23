//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
////Way1: ³¬Ê±
////bool BackTracking(string s, unordered_set<string> &hashDict)
////{
////	if (s.length() == 0) return true;
////	
////	for (int i = 1; i < s.length()+1; i++)
////	{
////		if (hashDict.count(s.substr(0, i)) && BackTracking(s.substr(i), hashDict)) return true;
////	}
////	return false;
////}
////
////bool wordBreak(string s, vector<string>& wordDict) {
////	unordered_set<string> hashDict(wordDict.begin(), wordDict.end());
////	return BackTracking(s,hashDict);
////}
//
//
////Way2: DP
////int DP(string s, unordered_set<string> &hashDict, vector<int> &memo,int index)
////{
////	if (index == 0) return 1;
////	if (memo[index] != 2)   return memo[index];
////
////	for (int i = index - 1; i >= 0; i--)
////	{
////		if (hashDict.count(s.substr(i, index - i)) && DP(s, hashDict, memo, i) == 1) return memo[index] = 1;
////	}
////	return memo[index] = 0;
////}
////bool wordBreak(string s, vector<string>& wordDict) {
////	unordered_set<string> hashDict(wordDict.begin(), wordDict.end());
////	vector<int> memo(s.length()+1, 2); //2 not visted 
////	DP(s, hashDict, memo, s.length());
////	return memo[s.length()];
////	//return false;
////}
//
////Way3: DP bottom to top
////bool wordBreak(string s, vector<string>& wordDict) {
////	unordered_set<string> hashDict(wordDict.begin(), wordDict.end());
////	vector<bool> memo(s.length()+1, false);
////	memo[0] = true;
////	for (int i = 1; i <= s.length(); i++)
////	{
////		for (int j = 1; j <= i; j++)
////		{
////			if (hashDict.count(s.substr(j-1, i - j + 1)) && memo[j-1])
////			{
////				memo[i] = true;
////				break;
////			}
////		}
////	}
////	return memo[s.length()];
////}
//
//int main()
//{
//	string s = "leetcode";
//	vector<string> wordDict = { "leet", "code" };
//	//cout << s.substr(1, 1);
//	cout << wordBreak(s,wordDict);
//	system("Pause");
//	return 0;
//}