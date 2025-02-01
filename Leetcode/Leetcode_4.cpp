

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int length1 = nums1.size();
	int length2 = nums2.size();
	int a = int((length1 + length2) / 2);
	nums1.insert(nums1.end(), nums2.begin(), nums2.end());
	sort(nums1.begin(), nums1.end());
	if ((length1 + length2) % 2 == 0)
	{
		return ( double(nums1[a-1] + nums1[a])/2);
	}
	else
	{
		return nums1[a];
	}
}

int main()
{
	vector<int> nums1(2);
	vector<int> nums2(2);
	nums1[0] = 1;
	nums1[1] = 3;
	nums2[0] = 2;
	nums2[1] = 4;
	cout << findMedianSortedArrays (nums1,nums2)<< endl;
	system("Pause");
	return 0;
}
*/