
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

void check(vector<int> & nums, int checkpoint, int &down, int & up,int target)
{
	up = checkpoint;
	down = checkpoint;
	while (( --down > -1 && nums[down] == target)){}
	while ((++up < nums.size() && nums[up] == target)) {}
}


vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res = {-1,-1};
	if (nums.size() == 0) return res;
	if (nums.size() == 1)
	{
		if (target == nums[0])
		{
			res[0] = 0;
			res[1] = 0;
			return res;
		}
		return res;
	}
	if (target < nums[0]) return res;
	if (target > nums[nums.size() - 1]) return res;
	int l = 0;
	int r = nums.size() - 1;
	int m = 0;
	int down = 0;
	int up = 0;

	while (l<=r)
	{
		m = (l + r) / 2;
		if (target == nums[m])
		{
			check(nums, m, down, up, target);
			if ( down == -1) res[0] = 0;
			else res[0] = down + 1;
			if (up == nums.size() ) res[1] = nums.size()-1;
			else res[1] = up - 1;
			return res;
		}
		else if (target > nums[m]) l = m + 1;
		else if (target < nums[m]) r = m - 1;
	}
	return res;
}

int main()
{
	vector<int> nums = {2,2};
	vector<int> res;
	res = searchRange(nums, 2);
	cout << res[0] << endl;
	cout << res[1] << endl;
	system("Pause");
	return 0;
}


*/