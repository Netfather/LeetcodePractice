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

//对于全部固定排序的，使用二分查找函数  额外需要补充起始位置和末尾位置
bool ToBsearch(vector<int> &nums, int target, int start, int end)
{
	if (end <= start) return false;
	if (target < nums[start] || target > nums[end]) return false;
	int middle = 0;
	while (start <= end)
	{
		middle = (start + end) / 2;
		if (nums[middle] > target) end = middle - 1;
		else if (nums[middle] < target) start = middle + 1;
		else return true;
	}
	return false;
}
bool search(vector<int>& nums, int target) {
	//step1: 按照顺序找奇点，同时search
	if (nums.empty()) return false;
	int roatatepoint = 0;
	int temp = nums[0];
	int i = 0;
	for (i = 0; i < nums.size(); i++)
	{
		if (target == nums[i]) return true;
		else if (target > temp && target < nums[i]) return false;
		else if (target > nums[i])
		{
			if (nums[i] < temp)
			{
				roatatepoint = i;
				break;
			}
		}
		temp = nums[i];
	}
	if (i == nums.size() - 1) return false;
	return ToBsearch(nums, target, i, nums.size() - 1);
}


int main()
{
	vector<int> test = { 1};
	cout << search(test,0)<<endl;
	system("Pause");
	return 0;
}
*/