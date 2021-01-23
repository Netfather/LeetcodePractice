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


int removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0) return 0;
	else if (nums.size() == 1)
	{
		if (nums[0] == val) return 0;
		else return 1;
	}
	else if (nums.size() > 1)
	{
		vector<int>::iterator ite;
		for (ite = nums.begin(); ite != nums.end();)
		{
			if (*ite == val)
			{
				ite = nums.erase(ite);
				continue;
			}
			ite++;
		}
	}
	return nums.size();
}
int main()
{
	vector<int> res = { 1, 1,2,2, 3, 3 };
	cout << removeElement(res, 2) << endl;
	return 0;
}

*/