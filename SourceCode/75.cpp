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
//�������ʹ���Դ���������
//��ô��ʹ���������� l  m  r
//ͨ��ά������������������ͣ��swap���Դﵽһ�α�����������Ŀ�ġ�
void sortColors(vector<int>& nums) {
	int l = 0;
	int m = 0;
	int r = nums.size() - 1;

	//��ʼ������
	for ( m = l; m <= r;m++)
	{
		if (nums[m] == 0)
		{
			swap(nums[l], nums[m]);
			l++;
		}
		else if (nums[m] == 2)
		{
			while (r >= m && nums[m] == 2)
			{
				swap(nums[r], nums[m]);
				r--;
			}
			while (m >= l && nums[m] == 0)
			{
				swap(nums[l], nums[m]);
				l++;
			}
		}
	}
}

int main()
{
	vector<int> nums = { 2, 0, 2, 1, 1, 0 };
	sortColors(nums);
	for (auto m : nums) cout << m << " ";
	cout << endl;
	system("Pause");
	return 0;
}
*/

