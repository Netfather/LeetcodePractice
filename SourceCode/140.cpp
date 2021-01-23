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
//bool DP(const string s, unordered_set<string> &hashDict, vector<vector<string>> &memo,int index)
//{
//	if (index == 0) return true;
//	if (!memo[index].empty())
//	{
//		if (memo[index][0] != "0") return true;
//		else return false;
//	}
//
//	for (int i = index - 1; i >= 0; i--)
//	{
//		string temp = s.substr(i, index - i);
//		if (hashDict.count(temp) && DP(s, hashDict, memo, i))
//		{
//			for (auto j : memo[i])
//			{
//				if(j == "") memo[index].push_back(temp);
//				else memo[index].push_back(j + " " + temp);
//			}
//		}
//	}
//	if (!memo[index].empty()) return true;
//	memo[index].push_back("0");
//	return false;
//}
//vector<string> wordBreak(string s, vector<string>& wordDict) {
//	unordered_set<string> hashDict(wordDict.begin(), wordDict.end());
//	vector<vector<string>> memo(s.length() + 1,vector<string>()); //if memo[] is null means not visited if not have res it is null {}
//	memo[0].push_back("");
//	DP(s, hashDict, memo, s.length());
//	if (memo[s.length()].size() == 1 && memo[s.length()][0]=="0") return {};
//	else return memo[s.length()];
//}
//
//
//int main()
//{
//	string s = "catsanddog";
//	vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
//	vector<string> output;
//	output = wordBreak(s, wordDict);
//	for (auto i : output) cout << i << endl;
//	system("Pause");
//	return 0;
//}