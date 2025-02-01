//算法笔记，这道题主要考察vector容器的使用方法，基础知识，包括构造之类的
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result(2);
	int res = 0;
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		res = target - nums.at(i);
		for (int j = i + 1; j < length ; j++)
		{
			if (nums[j] == res)
			{
				result[0] = i;
				result[1] = j;
				break;
			}
		}
		if (result[0] != 0) break;
	}
	return result;
};

/*
int main()
{
	int iArray[] = { 3, 2, 4 };
	vector<int> input(iArray, iArray + 3);
	vector<int> temp(twoSum(input,6));
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp.at(i) << "  ";
	}
	system("Pause");
	return 0;
}
*/