/*

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int length = nums.size();
	if (length == 3) return nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	int i = 0;
	int l = 0;
	int r = 0;
	int target_new = 0;
	int flag_l = 0;
	int temp_l = 0;
	int flag_r = 0;
	int temp_r = 0;
	int temp_res = nums[0] + nums[1] + nums[2];
	int pre_res = 0;
	for (i = 0; i < nums.size() -1 ; i++)
	{
		target_new = target - nums[i];
		l = i + 1;
		r = length - 1;
		while (l < r)
		{
			if (nums[l] + nums[r] == target_new) return target;
			else if (nums[l] + nums[r] < target_new)
			{
				//如果到头了 直接进行保存
				if (l == r - 1)
				{
					pre_res =  nums[i] + nums[l] + nums[r];
				}
				temp_l = nums[l] + nums[r];
				flag_l = 1;
				l++;
			}
			else if (nums[l] + nums[r] > target_new)
			{
				//如果到头了 直接进行保存
				if (l == r - 1)
				{
					pre_res = nums[i] + nums[l] + nums[r];
				}
				temp_r = nums[l] + nums[r];
				flag_r = 1;
				r--;
			}
			if (flag_r == 1 && flag_l == 1)
			{
				flag_r = 0;
				flag_l = 0;
				if (abs(temp_r - target_new) > abs(temp_l - target_new))
				{
					pre_res = temp_l + nums[i];
				}
				else if (abs(temp_r - target_new) <= abs(temp_l - target_new))
				{
					pre_res = nums[i]+ temp_r;
				}
				//如果到头了 直接进行保存在完成一次之后，直接进行覆盖
				if (abs(temp_res - target) > abs(pre_res - target)) temp_res = pre_res;
			}
		}
		//直接进行覆盖
		if (abs(temp_res - target) > abs(pre_res - target)) temp_res = pre_res;
		flag_r = 0;
		flag_l = 0;
	}
	return temp_res;
}




int main()
{
	vector<int> input = { 1, 6, 9, 14, 16, 70 };
	cout << threeSumClosest(input,81) << endl;
	system("Pause");
	return 0;
}


*/