
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

//首先定位可以蓄水的区间
int trap(vector<int>& height) {
	if (height.size() <= 2) return 0;
	vector<int>::iterator ite = height.begin();
	height.insert(ite, 0); //首元素插入0
	ite = height.end();
	height.insert(ite, 0); //尾元素插入0

	int res = 0;
	int i = 1;
	int j = 0;
	int standard = 0;
	
	int flag_l = 0;
	int flag_r = 0;
	int l = 0;
	int r = 0;

	vector<int> boudary;

	for (; i < height.size()-1; i++)
	{
		if (height[i - 1] - height[i] <= 0 && height[i+1] - height[i] < 0 )
		{
			if (flag_l == 0 && flag_r == 0)
			{
				flag_l = 1;
				l = i;
			}
			else if (flag_l == 1 && flag_r == 0)
			{
				flag_r = 1;
				r = i;
			}
			if (flag_l == 1 && flag_r == 1)
			{
				standard = min(height[l], height[r]);
				for (int j = l; j <= r; j++)
				{
					if (height[j] <= standard)	res = res + (standard - height[j]);
				}
				l = r;
				flag_l = 1;
				flag_r = 0;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int k = trap(height);
	cout << k << endl;
	system("Pause");
	return 0;
}

*/