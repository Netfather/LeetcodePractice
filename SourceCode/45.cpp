
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

int jumpdp(vector<int> &nums,int i, vector<int> & memo,int &res,int tempres)
{
	if (i >= nums.size()) return nums.size();
	else if (i == nums.size() - 1)
	{
		if (tempres < res) res = tempres;
		return tempres;
	}

	if (memo[i] != nums.size()) return memo[i];

	for (int j = nums[i]; j >0; j--)
	{
		memo[i] = jumpdp(nums, i + j, memo, res, tempres + 1);
	}
	return memo[i];
}

int jump(vector<int>& nums) {
	int res = nums.size() - 1;
	vector<int> memo(nums.size());
	for (int i = 0; i < memo.size(); i++)
	{
		memo[i] = nums.size();
	}
	jumpdp(nums,0,memo,res,0);
	return res;
}


int jump(vector<int>& nums) {






}

int main()
{
	vector<int> input = { 6, 2, 6, 1, 7, 9, 3, 5, 3, 7, 2, 8, 9, 4, 7, 7, 2, 2, 8, 4, 6, 6, 1, 3 };
	int k = jump(input);
	cout << k << endl;
	system("Pause");
	return 0;
}
*/