
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

bool canJump(vector<int>& nums) {
	if (nums.empty()) return false;
	if (nums.size() == 1 && nums[0] == 0) return true;

	int end_index = nums.size();
	int start = 0;
	int end = nums[0];
	int Maxend = 0;
	int cnt = 0;

	for (int i = start; i < end+1; i++)
	{
		int k = i + nums[i];
		if (k >= end_index - 1 ) return true;
		else if (k > end) Maxend = k;
		else if (k <= end)
		{
			++cnt;
		}
		if (i == end)
		{
			if (cnt < end - start + 1)
			{
				cnt = 0;
				start = end;
				end = Maxend;
			}
			else break;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	cout << canJump(nums) << endl;
	system("Pause");
	return 0;

}
*/