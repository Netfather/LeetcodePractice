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


Way 1: 使用erase函数 但是速度很慢 最简单的方法是
int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator ite;
	if (nums.size() == 0)return 0;
	else if (nums.size() == 1) return 1;
	else if (nums.size() > 1)
	{
		int temp = nums[0];
		for (ite = nums.begin() + 1; ite != nums.end();)
		{
			if (*ite == temp)
			{
				ite = nums.erase(ite);
				continue;
			}
			temp = *ite;
			ite++;
		}
	}
	return nums.size();
}


int removeDuplicates(vector<int>& nums) {
	int cnt = 0;
	vector<int>::iterator ite;
	vector<int>::iterator ite_begin;
	vector<int>::iterator temp;
	if (nums.size() == 0)return 0;
	else if (nums.size() == 1) return 1;
	else if (nums.size() > 1)
	{
		temp = nums.begin();
		int flag = 0;
		for (ite = nums.begin() + 1; ite != nums.end();)
		{
			if (cnt == 0)
			{
				ite_begin = temp;
			}
			if (*ite == *temp)
			{
				cnt++;
				if (ite == nums.end() - 1)
				{
					ite = nums.erase(ite_begin, ite);
				}
			}
			else if (*ite != *temp && cnt > 0)
			{
				ite = nums.erase(ite_begin, ite-1);
				cnt = 0;
			}
			temp = ite;
			ite++;
		}
	}
	return nums.size();
}


int main()
{
	vector<int> res = { 1, 1,3,3 };
	cout << removeDuplicates(res) << endl;
	system("Pause");
	return 0;
}

*/