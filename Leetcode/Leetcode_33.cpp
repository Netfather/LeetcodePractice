
/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//使用find函数可直接得解，如果不用 
int search(vector<int>& nums, int target) {
	if (nums.size() == 0) return  -1;
	if (nums.size() == 1)
	{
		if (nums[0] == target) return 0;
		else return -1;
	}
	//寻找breakingpoint 一边判断
	int length = nums.size();
	int i = 0;
	int breakpoint = 0;


	if (nums[0] < target)
	{
		for (i = 0; i < length; i++)
		{
			if (nums[i] == target) return i;
			if (i >= 1)
			{
				if (nums[i] - nums[i - 1] < 0) return -1;
			}
		}
	}
	else if (nums[0] > target)
	{
		for (i = length - 1; i >= 0; i--)
		{
			if (nums[i] == target) return i;
			if (i <= length - 2)
			{
				if (nums[i] - nums[i + 1] > 0) return -1;
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> nums = { 1, 3 };
	search(nums, 0);

	return 0;
}

*/