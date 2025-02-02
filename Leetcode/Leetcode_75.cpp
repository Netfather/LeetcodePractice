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
//如果不能使用自带的排序函数
//那么就使用三个参数 l  m  r
//通过维护好这三个参数来不停的swap可以达到一次遍历完成排序的目的。
void sortColors(vector<int>& nums) {
	int l = 0;
	int m = 0;
	int r = nums.size() - 1;

	//初始化参数
	for ( m = l; m <= r;m++)
	{
		if (nums[m] == 0)
		{
			swap(nums[l], nums[m]);
			l++;
		}
		else if (nums[m] == 2)
		{
			while (r >= m && nums[m] == 2)
			{
				swap(nums[r], nums[m]);
				r--;
			}
			while (m >= l && nums[m] == 0)
			{
				swap(nums[l], nums[m]);
				l++;
			}
		}
	}
}

int main()
{
	vector<int> nums = { 2, 0, 2, 1, 1, 0 };
	sortColors(nums);
	for (auto m : nums) cout << m << " ";
	cout << endl;
	system("Pause");
	return 0;
}
*/

