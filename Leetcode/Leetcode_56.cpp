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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	if (intervals.empty()) return res;
	if (intervals.size() == 1) return intervals;
	sort(intervals.begin(), intervals.end());
	res.push_back(intervals[0]);
	int cnt = 0;
	int flag = 0;

	for (int i = 1; i < intervals.size(); i++)
	{
		cnt = 0;
		flag = 0;
		for (int j = 0; j < res.size(); j++)
		{
			if (intervals[i][0] > res[j][1] || intervals[i][1] < res[j][0]) ++cnt;
			else
			{
				res[j][0] = min(res[j][0], intervals[i][0]);
				res[j][1] = max(res[j][1], intervals[i][1]);
				flag = 1;
				break;
			}
		}
		if (flag == 0 && cnt == res.size() )
		{
			res.push_back(intervals[i]);
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> intervals = { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, { 1, 10 } };
	vector<vector<int>> res;
	res = merge(intervals);
	for (auto m : res)
	{
		for (auto n : m)
		{
			cout << n << "   ";
		}
		cout << endl;
	}
	system("Pause");
	return 0;
}

*/