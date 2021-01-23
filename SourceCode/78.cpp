
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

void DFS(vector<vector<int>> &res, vector<int> &tempres, int step, int k, int n, vector<int>& nums)
{
	if (step == k)
	{
		res.push_back(tempres);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!tempres.empty() && nums[i] <= tempres[tempres.size() - 1]) continue;
		tempres.push_back(nums[i]);
		DFS(res, tempres, step + 1, k, n,nums);
		tempres.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> tempres;
	if (nums.empty()) return res;
	for (int i = 0; i <= nums.size(); i++)
	{
		DFS(res, tempres, 0, i, nums.size(),nums);
	}
	return res;

}

int main()
{
	vector < vector < int >> res;
	vector<int> input = { 1,2,3 };
	res = subsets(input);
	for (auto k : res)
	{
		for (auto m : k)
		{
			cout << m << "  ";
		}
		cout << endl;
	}
	system("Pause");
	return 0;
}
*/