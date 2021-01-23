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
////Way1: Hashmap
////int singleNumber(vector<int>& nums) {
////	unordered_set<int> set;
////	for (auto i : nums)
////	{
////		if (!set.count(i)) set.insert(i);
////		else set.erase(i);
////	}
////	return *set.begin();
////}
////Way2: Sort
////int singleNumber(vector<int>& nums) {
////	sort(nums.begin(), nums.end());
////	for (int i = 1; i < nums.size(); i++)
////	{
////		if (nums[i] != nums[i - 1]) return nums[i - 1];
////		i++;
////	}
////	return nums.back();
////}
//
//
//int main()
//{
//	vector<int> nums = { 1,1,2 };
//	cout << singleNumber(nums);
//	system("Pause");
//	return 0;
//}