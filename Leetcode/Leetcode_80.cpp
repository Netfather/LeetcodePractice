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

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	else if(nums.size() <= 2) return nums.size();
	int cnt = 2;
	int tmp1 = nums[0];
	int tmp2 = nums[1];
	for (int i = 2; i < nums.size();i++)
	{
		if (nums[i] == tmp1)
		{
			nums.erase(nums.begin() + i);
			--i;
		}
		else if (nums[i] == tmp2)	cnt++;
		tmp1 = tmp2;
		tmp2 = nums[i];
	}
	return nums.size();
}

int main()
{
	vector<int> input = { 1, 1, 1, 2, 2, 3 };
	int k = removeDuplicates(input);
	for (auto i : input)
	{
		cout << i << "  ";
	}
	cout << k;
	system("Pause");
	return 0;
}

*/