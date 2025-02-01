

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


int maxSubArray(vector<int>& nums) {
	if (nums.empty()) return 0;
	else if (nums.size() == 1) return nums[0];
	int tempres = 0;
	int res = 0;
	int cnt = 0;
	int temp = INT_MIN;
	int flag = 0;

	nums.insert(nums.begin(), -1);
	for (int i = 1; i < nums.size(); i++)
	{
		tempres = 0;
		if (nums[i - 1] <= 0 && nums[i] >= 0)
		{
			for (int j = i; j < nums.size(); j++)
			{
				if (nums[j-1] >= 0 && nums[j] <= 0)
				{
					if (tempres >= res) res = tempres;
				}
				tempres = tempres + nums[j];
			}
			if (tempres >= res) res = tempres;
		}
		else
		{
			if (nums[i] > temp) temp = nums[i];
			cnt++;
		}
	}
	if (cnt == nums.size() -1 ) return temp;
	else return res;
}




int main()
{
	vector<int>input = { -1, -2};
	cout << maxSubArray(input)<<endl;
	system("Pause");
	return 0;
}

*/