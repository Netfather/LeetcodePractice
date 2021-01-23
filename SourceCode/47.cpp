
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


void Permute(vector<int> &nums, vector<bool> &test_last ,vector<int> &tempres, vector<vector<int>> &res, int step, vector<int> &index)
{
	if (step == nums.size())
	{
	//	for (vector<int> k : res) if (k == tempres) return;
		res.push_back(tempres);
		return;
	}
	int flag = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		flag = 0;
		for (int k : index)		if (k == i) flag = 1;
		if (flag == 1) continue;

		if (i>0 && test_last[i-1] == false && nums[i] == nums[i - 1]) continue; //删除相同的根子树

		index.push_back(i);
		tempres.push_back(nums[i]);
		test_last[i] = true;
		Permute(nums,test_last,tempres, res, step + 1,index);
		test_last[i] = false;
		tempres.pop_back();
		index.pop_back();
	}
	return;
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.empty()) return res;
	vector<int> tempres;
	vector<int> index; //用于存储已经走过路径的下标
	vector<bool> test_last(nums.size());//用于记录元素是否为上一层
	sort(nums.begin(), nums.end());
	Permute(nums,test_last,tempres, res, 0,index);
	return res;
}


int main()
{
	vector<int> input = {1,1,2};
	vector<vector<int>> res;
	res = permuteUnique(input);
	for (vector<int> m : res)
	{
		for (int n : m) cout << n << "  ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

*/