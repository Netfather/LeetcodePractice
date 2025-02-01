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
//
//
////Way1: 使用sort排序很直白的获得结果
//int maximumGap(vector<int>& nums) {
//	if (nums.empty()) return 0;
//	sort(nums.begin(), nums.end());
//	int res = 0;
//	for (int i = 0; i < nums.size() - 1; i++) res = max(res, nums[i + 1] - nums[i]);
//	return res;
//}
//
////Way2： DP+ list 来做
//
//
//int maximumGap(vector<int>& nums) {
//	if (nums.empty()) return 0;
//	sort(nums.begin(), nums.end());
//	int start = 0;
//	int end = nums.size() - 1;
//	int mid = (start + end) / 2;
//	while (start + 1 < end)
//	{
//		if(nums[mid] - nums[start] > nums[end] - nums[mid])
//	}
//
//
//}
