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
////法1： 暴力搜索+减枝
////bool IsPaldin(string input, int end)
////{
////	string temp = input.substr(0, end + 1);
////	string retemp = temp;
////	reverse(temp.begin(), temp.end());
////	if (retemp == temp) return true;
////	return false;
////}
////
////void CurSearch(string sub_s,vector<string> &tempres,vector<vector<string>> &res)
////{
////	if (sub_s.empty())
////	{
////		res.push_back(tempres);
////		return;
////	}
////	for (int i = 0; i < sub_s.size(); i++)
////	{
////		if (IsPaldin(sub_s, i))
////		{
////			tempres.push_back(sub_s.substr(0,i+1));
////			CurSearch(sub_s.substr(i+1, sub_s.size()), tempres, res);
////			tempres.pop_back();
////		}
////	}
////	return;
////}
////
////vector<vector<string>> partition(string s) {
////	vector<string> tempres;
////	vector<vector<string>> res;
////	if (s.empty()) return res;
////	CurSearch(s, tempres, res);
////	return res;
////}
//
//
////法2 加入dp memo思想，在减枝过程中，我们会发现其实有很多的IsPaldin判定是被重复的，因此引入memo表格
//bool IsPaldin_memo(string &s, int start,int end,vector<vector<int>> &memo)
//{
//	if (memo[start][end] == 1) return true;
//	else if (memo[start][end] == 2) return false;
//	else
//	{
//		while (start < end)
//		{
//			if (s[start] != s[end])
//			{
//				memo[start][end] = 2;
//				return false;
//			}
//			start++;
//			end--;
//		}
//		memo[start][end] = 1;
//		return true;
//	}
//}
//
//void DP(string &s, vector<string> &tempres, vector<vector<string>> &res, vector<vector<int>> &memo,int start)
//{
//	if (start == s.size())
//	{
//		res.push_back(tempres);
//		return;
//	}
//
//	for (int i = start; i < s.size(); i++)
//	{
//		if (IsPaldin_memo(s, start, i, memo))
//		{
//			tempres.push_back(s.substr(start, i-start + 1));
//			DP(s, tempres, res, memo, i + 1);
//			tempres.pop_back();
//		}
//	}
//	return;
//}
//
//vector<vector<string>> partition(string s) {
//	vector<string> tempres;
//	vector<vector<string>> res;
//	if (s.empty()) return res;
//	vector<vector<int>>memo(s.size(), vector<int>(s.size(), 0)); //0表示未访问过，1表示可以，2表示该位置不行
//	DP(s, tempres, res,memo,0);
//	return res;
//}
//
//int main()
//{
//	string s = "aab";
//	vector<vector<string>> res;
//	res = partition(s);
//	for (auto i : res)
//	{
//		for (auto j : i) cout << j << "  ";
//		cout << endl;
//	}
//
//	system("Pause");
//	return 0;
//}