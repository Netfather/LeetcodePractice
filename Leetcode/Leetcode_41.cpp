
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

int firstMissingPositive(vector<int>& nums) {
	if (nums.size() == 0) return 1;
	if (nums.size() == 1 && nums[0] != 1) return 1;
	if (nums.size() == 1 && nums[0] == 1) return 2;
	sort(nums.begin(), nums.end());
	if (nums[nums.size() - 1] < 0) return 1;
	int count = 0;
	for (int temp : nums)
	{
		if (temp <= 0) count++;
		else break;
	}
	int i = count;
	if (nums[count] >= 2) return 1;
	else if (nums[count] == 1 && i == nums.size() - 1) return 2;
	while (i + 1 < nums.size() && (nums[i] - nums[++i] >= -1)){ }
	if (nums[i] - nums[i - 1] > 1) return nums[i - 1] + 1;
	else return nums[i] + 1;
}

int main()
{
	vector<int> nums = { -10, -3, -100, -1000, -239, 1 };
	int k = firstMissingPositive(nums);
	cout << k << endl;
	system("Pause");
	return 0;
}
*/