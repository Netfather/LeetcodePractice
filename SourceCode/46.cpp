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

void Permute(vector<int> &nums, vector<int> &tempres, vector<vector<int>> &res, int step)
{
	if (step == nums.size() )
	{
		res.push_back(tempres);
		return;
	}
	int flag = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		flag = 0;
		for (int k : tempres)
		{ 
			if (k == nums[i]) flag = 1; 
		}
		if (flag == 1) continue;
		tempres.push_back(nums[i]);
		Permute(nums, tempres, res, step + 1);
		tempres.pop_back();
	}
	return;
}


vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.empty()) return res;
	vector<int> tempres;
	Permute(nums, tempres, res, 0);
	return res;
}


int main()
{
	vector<int> input = { 1, 2, 3 };
	vector<vector<int>> res;
	res = permute(input);
	for (vector<int> m : res)
	{
		for (int n : m) cout << n<<"  ";
		cout << endl;
	}
	system("Pause");
	return 0;
}
*/