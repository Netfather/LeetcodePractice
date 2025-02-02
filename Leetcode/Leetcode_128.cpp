//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//
////Way1: 用sort取巧
////int longestConsecutive(vector<int>& nums) {
////	sort(nums.begin(), nums.end());
////	int tempres = 1;
////	if (nums.empty()) return 0;
////	if (nums.size() == 1) return 1;
////	int res = 0;
////	for (int i = 1; i < nums.size(); i++)
////	{
////		if (nums[i] == nums[i - 1]) continue;
////		if (nums[i] == nums[i - 1] + 1) ++tempres;
////		else
////		{
////			res = max(res, tempres);
////			tempres = 1;
////		}
////	}
////	return max(res, tempres);
////}
//
////Way2: 使用哈希表
//int longestConsecutive(vector<int>& nums)
//{
//	if (nums.empty()) return 0;
//	if (nums.size() == 1) return 1;
//	unordered_set<int> num(nums.begin(), nums.end()); //转到hashmap中
//	int res = 0;
//	int tempres = 1;
//	while (!num.empty())
//	{
//		int start = (*num.begin());
//		num.erase(start);
//		int rightbound = start;
//		while (num.count(++rightbound))
//		{
//			++tempres;
//			num.erase(rightbound);
//		}
//		int leftbound = start;
//		while (num.count(--leftbound))
//		{
//			++tempres;
//			num.erase(leftbound);
//		}
//		res = max(res, tempres);
//		tempres = 1;
//	}
//	return res;
//}
//
//
//int main()
//{
//	vector<int> input = { 0,-1 };
//	cout << longestConsecutive(input);
//	system("Pause");
//	return 0;
//}