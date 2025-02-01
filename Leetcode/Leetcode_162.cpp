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
//int findPeakElement(vector<int>& nums) {
//	if (nums.empty()) return -1;
//	if (nums.size() == 1) return 0;
//	for (int i = 0; i < nums.size() ; i++)
//	{
//		if(i == 0)
//		{
//			if (nums[i] > nums[i + 1]) return i;
//		}
//		else if(i == nums.size() - 1)
//		{
//			if (nums[i] > nums[i - 1]) return i;
//		}
//		else
//		{
//			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
//			if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	vector<int> nums = { 1,2,3,1 };
//	cout << findPeakElement(nums) << endl;
//	system("Pause");
//	return 0;
//}