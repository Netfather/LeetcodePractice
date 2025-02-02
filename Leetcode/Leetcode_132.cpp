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
////Way1: 动态规划
//bool IsPaldin_memo(string &s, int start, int end, vector<vector<int>> &memo)
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
//void isPalindrome(int start, int end, string &s, vector<vector<bool>> &palin) 
//{
//	if (start < 0 or end >= s.size()) return;
//	if (s[start] == s[end]) palin[start][end] = 1, isPalindrome(start - 1, end + 1,s,palin);
//}
//
//int DP_2(string &s, vector<vector<bool>> &palin, int start, int end, vector<int> &tempres)
//{
//	if (start == end) return 0;
//	if (palin[start][end]) return 0;
//
//	if (tempres[end] != -1) return tempres[end];
//
//	int res = INT_MAX;
//
//	for (int i = start; i <= end; i++)
//	{
//		if (palin[i][end])
//		{
//			res = min(res, DP_2(s, palin, 0, i - 1, tempres) + 1);
//		}
//	}
//	if (res == INT_MAX)
//	{
//		if (s[end] != s[end - 1]) res = DP_2(s, palin, 0, end - 1, tempres) + 1;
//		else res = DP_2(s, palin, 0, end - 1, tempres);
//	}
//	tempres[end] = res;
//	return res;
//}
//
//
//int minCut(string s) {
//	if (s.empty()) return 0;
//	vector<vector<int>>memo(s.size(), vector<int>(s.size(), 0)); //0表示未访问过，1表示可以，2表示该位置不行
//	vector<int> tempres(s.size(), -1);
//	vector<vector<bool>>palin(s.size(), vector<bool>(s.size(), 0));
//	for (int i = 0; i < s.size(); i++) {
//		isPalindrome(i, i,s,palin);
//		isPalindrome(i, i + 1,s,palin);
//	}
//	return DP_2(s, palin, 0, s.size() - 1, tempres);
//}
//
//////Way2: 贪心  不可
////bool DP(string &s, int &res, int &tempres, vector<vector<int>> &memo, int start, int end)
////{
////	if (start >= end)
////	{
////		res = tempres;
////		return true;
////	}
////	int left_bound = start;
////	int right_bound = end;
////	for (int i = end; i >= start; i--)
////	{
////		//每一步谁分割的最长，谁就是最好的
////		if (IsPaldin_memo(s, start, i, memo))
////		{
////			left_bound = i;
////			break;
////		}
////	}
////	for (int i = start; i <= end; i++)
////	{
////		if (IsPaldin_memo(s, i, end, memo))
////		{
////			right_bound = i;
////			break;
////		}
////	}
////	if (left_bound - start > end - right_bound)
////	{
////		++tempres;
////		if (DP(s, res, tempres, memo, left_bound + 1, end)) return true;
////		--tempres;
////	}
////	else if (left_bound - start < end - right_bound)
////	{
////		++tempres;
////		if (DP(s, res, tempres, memo, 0, right_bound - 1)) return true;
////		--tempres;
////	}
////	else
////	{
////		if (left_bound < right_bound)
////		{
////			tempres += 2;
////			if (DP(s, res, tempres, memo, left_bound + 1, right_bound - 1)) return true;
////			tempres -= 2;
////		}
////		else
////		{
////			
////
////		}
////
////	}
////	return false;
////}
////
////int minCut(string s) {
////	if (s.empty()) return 0;
////	vector<vector<int>>memo(s.size(), vector<int>(s.size(), 0)); //0表示未访问过，1表示可以，2表示该位置不行
////	int res = 0;
////	int tempres = 0;
////	if(DP(s, res,tempres, memo, 0,s.size() - 1)) return res;
////	return res;
////
////}
//
//
//int main()
//{
//	//string s = "jcggcgfjj";
//	string s = "aab";
//	//string s = "eegiicegghjjd";
//	int res;
//	res = minCut(s);
//	cout << res << endl;
//	system("Pause");
//	return 0;
//}
//
