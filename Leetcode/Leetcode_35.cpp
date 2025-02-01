
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

int searchInsert(vector<int>& nums, int target) {
	if (nums.size() == 0) return -1;
	if (target < nums[0]) return 0;
	if (target > nums[nums.size() - 1]) return nums.size();
	int l = 0;
	int r = nums.size() - 1;
	int m = 0;
	
	while (l <= r)
	{
		m = (l + r) / 2;
		if (nums[m] == target) return m;
		else if (nums[m] < target)		l = m + 1;
		else if (nums[m] > target)		r = m - 1;
		if (l == r)
		{
			if (nums[l] == target) return l;
			else if (nums[l] < target) return l + 1;
			else return l;
		}
	}
	return (l+r) / 2 + 1;
}

int main()
{
	vector<int> nums = { 3,5,7,9,10};
	cout << searchInsert(nums,8);
	system("Pause");
	return 0;
}


*/