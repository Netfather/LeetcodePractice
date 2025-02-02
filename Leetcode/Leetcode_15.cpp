/*
//输入的数字不相等
//只需要检测完成非正数部分
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i<n; i++){
		if ( (i == 0 || (i != 0 && nums.at(i) != nums.at(i - 1))) && nums.at(i) <=0  ){
			int a = nums.at(i);
			int l = i + 1;
			int r = n - 1;
			int target = -a;
			while (l<r){
				int sum = nums.at(l) + nums.at(r);
				if (sum == target){
					result.push_back({ a, nums.at(l), nums.at(r) });
					while (l < r && nums.at(l) == nums.at(l + 1))
						l++;
					while (l < r && nums.at(r) == nums.at(r - 1))
						r--;
					l++; r--;
				}
				else if (sum > target){
					r--;
				}
				else{
					l++;
				}
			}
		}
	}
	return result;
}


int main()
{
	vector<int> input = { 0, 0, 0, 0 };
	vector<vector<int>> output= threeSum(input);
	cout << output.size() << endl;
	system("Pause");
	return 0;
}

*/