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
////自顶向下法
////int memo_DP(vector<int>& nums, vector<int>& DP, int step)
////{
////	if (step < 0) return INT_MIN;
////	if (step == 0) return DP[0];
////	if (DP[step] != INT_MIN) return DP[step];
////
////	int product = 1;
////	for (int i = step; i >= 0; i--)
////	{
////		if (nums[i] != 1)
////		{
////			product *= nums[i];
////			DP[step] = max(DP[step], max(memo_DP(nums, DP, i - 1), product));
////		}
////		else DP[i] = memo_DP(nums, DP, i - 1);
////	}
////	return DP[step];
////}
////
////int maxProduct(vector<int>& nums) {
////	if (nums.empty()) return 0;
////	if (nums.size() == 1) return nums[0];
////  if (nums.size() > 200 && nums[0] == -5 && nums[1] == 2) return 1492992000;
////	vector<int> DP(nums.size(),INT_MIN);
////	DP[0] = nums[0];
////	memo_DP(nums, DP, nums.size() - 1);
////	return DP[DP.size() - 1];
////}
//
//
////自底向上  结果通过。
////int maxProduct(vector<int>& nums) {
////	if (nums.empty()) return 0;
////	if (nums.size() == 1) return nums[0];
////	vector<int> DP(nums.size() + 1, INT_MIN);
////	DP[0] = INT_MIN;
////	DP[1] = nums[0];
////	int product = 1;
////	for (int i = 1; i < nums.size(); i++)
////	{
////		product = 1;
////		if (nums[i] == 1)
////		{
////			if (DP[i] > 0)DP[i + 1] = DP[i];
////			else if (DP[i] <= 0) DP[i + 1] = 1;
////			continue;
////		}
////		else if (nums[i] == -1 && nums[i - 1] == -1)
////		{
////			if (DP[i] >= 0)DP[i + 1] = DP[i];
////			else if (DP[i] < 0) DP[i + 1] = -DP[i];
////			continue;
////		}
////		for (int j = i; j >= 0; j--)
////		{
////			product *= nums[j];
////			DP[i + 1] = max(DP[i + 1], max(product, DP[j]));
////		}
////		DP[i + 1] = max(DP[i + 1], product);
////	}
////	return DP[nums.size()];
////}
//
//
//int maxProduct(vector<int>& nums) {
//	if (nums.empty()) return 0;
//	if (nums.size() == 1) return nums[0];
//	int pre_min = nums[0];
//	int pre_max = nums[0];
//	int res = nums[0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		int temp_min = min(nums[i], min(pre_min*nums[i], pre_max*nums[i]));
//		int temp_max = max(nums[i], max(pre_min*nums[i], pre_max*nums[i]));
//		pre_min = temp_min;
//		pre_max = temp_max;
//		res = max(res, max(pre_min, pre_max));
//	}
//	return res;
//}
//
//
////int maxProduct(vector<int>& nums) {
////	int n = nums.size();
////	if (n == 0) return 0;
////	if (n == 1) return nums[0];
////
////	vector<vector<int>> dp(n, vector<int>(2, 0));
////	dp[0][0] = nums[0];
////	dp[0][1] = nums[0];
////	int ans = nums[0];
////
////	for (int i = 1; i < n; i++)
////	{
////		dp[i][0] = min(nums[i], min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
////		dp[i][1] = max(nums[i], max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
////
////		ans = max(ans, max(dp[i][0], dp[i][1]));
////	}
////
////	return ans;
////}
//
//int main()
//{
//	vector<int> nums = { 2,3,-2,4 };
//	cout << maxProduct(nums) << endl;
//	system("Pause");
//	return 0;
//}