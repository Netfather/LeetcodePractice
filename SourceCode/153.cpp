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
//int findMin(vector<int>& nums) {
//	if (nums.empty()) return 0;
//	if (nums.size() == 1) return nums[0];
//	if (nums[0] < nums[nums.size() - 1]) return nums[0]; //No roated
//
//	int start = 0;
//	int end = nums.size() - 1;
//	int mid = (start + end) / 2;
//	while (start + 1 < end)
//	{
//		if (mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) return nums[mid];
//		if (nums[mid] > nums[end]) start = mid;
//		else end = mid;
//		mid = (start + end) / 2;
//	}
//	return nums[start] > nums[end] ? nums[end] : nums[start];
//}