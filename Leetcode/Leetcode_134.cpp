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
//
////int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
////	int sum = 0;
////	int tempsum = 0;
////	vector<int> startset;
////	for (int i = 0; i < gas.size(); i++)
////	{
////		if (i > 0) if (gas[i] - cost[i] >= 0 && gas[i - 1] - cost[i - 1] < 0) startset.push_back(i);
////		if (i == 0) if (gas[i] - cost[i] >= 0)  startset.push_back(i);
////		sum += (gas[i] - cost[i]);
////	}
////	if (sum < 0) return -1;
////	for (int i = 0; i < startset.size(); i++)
////	{
////		int index = startset[i];
////		int flag = 0;
////		int totalsum = 0;
////		int m = 0;
////		int n = 0;
////		for (m = index; m < gas.size(); m++)
////		{
////			totalsum += (gas[m] - cost[m]);
////			if (totalsum < 0)
////			{
////				flag = 1;
////				break;
////			}
////		}
////		for (n = 0; n < index; n++)
////		{
////			if (flag == 1) break;
////			totalsum += (gas[n] - cost[n]);
////			if (totalsum < 0) break;
////		}
////		if (n == index && m == gas.size()) return index;
////	}
////	return -1;
////}
//
////Way2 如果存在一个这样的结果，由于其唯一性，那么这个结果一定在 差值最大站的下一个站点,因为如果不在这个站点，那么就一定是没有结果的
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//	int totalsum = INT_MAX;
//	int tempsum = 0;
//	int tempindex = 0;
//	for (int i = 0; i < gas.size(); i++)
//	{
//		tempsum += gas[i] - cost[i];
//		if (tempsum < totalsum)
//		{
//			totalsum = tempsum;
//			tempindex = i;
//		}
//	}
//	if (tempsum < 0) return -1;
//	return tempindex + 1;
//}
//
//int main()
//{
//	vector<int> gas = { 1,7,6,4,8,5};
//	vector<int> cost = { 8,5,4,6,1,7};
//
//	cout << canCompleteCircuit(gas, cost);
//	system("Pause");
//	return 0;
//}