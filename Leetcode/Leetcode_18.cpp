
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

#define pre nums[i]+nums[j]+nums[l]+nums[r]


vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums[0] + nums[1] + nums[2] + nums[3] > target) return res;
	if (nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] + nums[nums.size() - 4] < target) return res;
 	if (nums.size() == 4)
	{
		if (nums[0] + nums[1] + nums[2] + nums[3] == target)
		{
			res.push_back(nums);
			return res;
		}
		else return res;
	}
	else if (nums.size() > 4)
	{
		int i = 0;
		int j = 0;
		int l = 0;
		int r = 0;
		for (i = 0; i < nums.size() - 3; i++ )
		{
			if (i == 0)
			{
				for (j = i + 1; j < nums.size() - 2; j++)
				{
					if (j == i + 1)
					{
						l = j + 1;
						r = nums.size() - 1;
						while (l < r)
						{
							if (pre == target)
							{
								res.push_back({ nums[i], nums[j], nums[l], nums[r] });
								while (l < r && nums.at(l) == nums.at(l + 1))
									l++;
								while (l < r && nums.at(r) == nums.at(r - 1))
									r--;
								l++;
								r--;
							}
							else if (pre < target) l++;
							else if (pre > target) r--;
						}
					}
					else if (j > i + 1)
					{
						if (nums[j] != nums[j - 1])
						{
							l = j + 1;
							r = nums.size() - 1;
							while (l < r)
							{
								if (pre == target)
								{
									res.push_back({ nums[i], nums[j], nums[l], nums[r] });
									while (l < r && nums.at(l) == nums.at(l + 1))
										l++;
									while (l < r && nums.at(r) == nums.at(r - 1))
										r--;
									l++;
									r--;
								}
								else if (pre < target) l++;
								else if (pre > target) r--;
							}
						}
						else if (nums[j] == nums[j - 1]) continue;
					}
				}
			}
			else if (i > 0)
			{
				if (nums[i] != nums[i - 1])
				{
					for (j = i + 1; j < nums.size() - 2; j++)
					{
						if (j == i + 1)
						{
							l = j + 1;
							r = nums.size() - 1;
							while (l < r)
							{
								if (pre == target)
								{
									res.push_back({ nums[i], nums[j], nums[l], nums[r] });
									while (l < r && nums.at(l) == nums.at(l + 1))
										l++;
									while (l < r && nums.at(r) == nums.at(r - 1))
										r--;
									l++;
									r--;
								}
								else if (pre < target) l++;
								else if (pre > target) r--;
							}
						}
						else if (j > i + 1)
						{
							if (nums[j] != nums[j - 1])
							{
								l = j + 1;
								r = nums.size() - 1;
								while (l < r)
								{
									if (pre == target)
									{
										res.push_back({ nums[i], nums[j], nums[l], nums[r] });
										while (l < r && nums.at(l) == nums.at(l + 1))
											l++;
										while (l < r && nums.at(r) == nums.at(r - 1))
											r--;
										l++;
										r--;
									}
									else if (pre < target) l++;
									else if (pre > target) r--;
								}
							}
							else if (nums[j] == nums[j - 1]) continue;
						}
					}
				}
				else if (nums[i] == nums[i - 1]) continue;
			}
		}
	}
	return res;
}


int main()
{
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> res;
	res = fourSum(nums, 0);
	for (vector<int> im : res)
	{
		for (int i : im)
		{
			cout << i;
		}
		cout << endl;
	}
	system("Pause");
	return 0;
}

*/