//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
////Way1: 结果正确 但是最后一个输入测试超时了
//int candy(vector<int>& ratings) {
//	if (ratings.size() == 0) return 0;
//	if (ratings.size() == 1) return 1;
//	if (ratings.size() == 2)
//	{
//		if (ratings[0] == ratings[1]) return 2;
//		return 3;
//	}
//	vector<int> res(ratings.size(), 0); //0表示该结果未赋值
//	int sum = 0;
//	int cnt = 0;
//	int flag = 0;
//	while (1)
//	{
//		for (int i = 0; i < ratings.size(); i++)
//		{
//			if (res[i] != 0) continue;
//			if (i == 0)
//			{
//				if (ratings[i] <= ratings[i + 1])
//				{
//					res[i] = 1;
//					sum += res[i];
//					++cnt;
//				}
//				else if (res[i + 1] != 0)
//				{
//					res[i] = res[i + 1] + 1;
//					sum += res[i];
//					++cnt;
//				}
//			}
//			else if (i == ratings.size() - 1)
//			{
//				if (ratings[i] <= ratings[i - 1])
//				{
//					res[i] = 1;
//					sum += res[i];
//					++cnt;
//				}
//				else if (res[i - 1] != 0)
//				{
//					res[i] = res[i - 1] + 1;
//					sum += res[i];
//					++cnt;
//				}
//			}
//			else
//			{
//				if (ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1])
//				{
//					if (res[i - 1] != 0 && res[i + 1] != 0)
//					{
//						res[i] = max(res[i + 1], res[i -1])+ 1;
//						sum += res[i];
//						++cnt;
//					}
//				}
//				else if (ratings[i] <= max(ratings[i - 1], ratings[i + 1]) && ratings[i] > min(ratings[i - 1], ratings[i + 1]))
//				{
//					if (res[i - 1] != 0 && ratings[i - 1] < ratings[i + 1])
//					{
//						res[i] = res[i - 1] + 1;
//						sum += res[i];
//						++cnt;
//					}
//					else if (res[i + 1] != 0 && ratings[i + 1] < ratings[i - 1])
//					{
//						res[i] = res[i + 1] + 1;
//						sum += res[i];
//						++cnt;
//					}
//				}
//				else
//				{
//					res[i] = 1;
//					sum += res[i];
//					++cnt;
//				}
//			}
//		}
//		if (flag == 0 && cnt < ratings.size() / 2)
//		{
//			flag == 1;
//			reverse(res.begin(), res.end());
//			reverse(ratings.begin(), ratings.end());
//		}
//		if (cnt == ratings.size()) break;
//	}
//	return sum;
//}
//
////Way2 DP method
//int candy2(vector<int>& ratings) {
//	if (ratings.size() == 0) return 0;
//	if (ratings.size() == 1) return 1;
//	if (ratings.size() == 2)
//	{
//		if (ratings[0] == ratings[1]) return 2;
//		return 3;
//	}
//	vector<int> res(ratings.size(), 0); //0表示该结果未赋值
//	res[0] = 1;
//	for (int i = 1; i < ratings.size(); i++)
//	{
//		if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
//		else res[i] = 1;
//	}
//	int temp_start = 1;
//	for (int i = ratings.size() - 2; i >= 0; i--)
//	{
//		if (ratings[i] > ratings[i + 1]) temp_start = temp_start + 1;
//		else temp_start = 1;
//		res[i] = max(res[i], temp_start);
//	}
//	int sum = 0;
//	for (auto i : res) sum += i;
//	return sum;
//}
//
//
//
//int main()
//{
//	//vector<int> input = {1,3,2,6,2,8,5,3,5,2,8};
//	vector<int> input = {3,6,12,6,34,62,46,135 };
//	cout << candy(input) << endl;
//	cout << candy2(input) << endl;
//	system("Pause");
//	return 0;
//}