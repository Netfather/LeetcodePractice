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
//	int b = nums[start] > nums[end] ? nums[end] : nums[start];
//	int mid = (start + end) / 2;
//	while (start + 1 < end)
//	{
//		int temp = nums[mid];
//		int sub_left = mid;
//		int sub_right = mid;
//		while (--sub_left >= 0 && nums[sub_left] == nums[mid]);
//		while (++sub_right < nums.size() && nums[sub_right] == nums[mid]);
//
//		if (sub_left == -1 && sub_right == nums.size()) return nums[0];
//		else if (sub_left == -1 && sub_right != nums.size())
//		{
//			start = sub_right;
//		}
//		else if (sub_right == nums.size() && sub_left != -1)
//		{
//			end = sub_left;
//		}
//		else
//		{
//			if (nums[mid] < nums[sub_left] && nums[mid] < nums[sub_right]) return nums[mid];
//			if (nums[mid] > nums[end]) start = sub_right;
//			else end = sub_left;
//		}
//		mid = (start + end) / 2;
//	}
//	int a =  nums[start] > nums[end] ? nums[end] : nums[start];
//	return a > b ? b : a;
//}
//
//int main()
//{
//	vector<int> nums = { 3,1,1 };
//	cout << findMin(nums);
//	system("Pause");
//	return 0;
//}