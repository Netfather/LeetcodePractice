//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <string>
//#include <vector>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//void freshbigger(vector<int>& bigtemp, int a)
//{
//	if (a <= bigtemp[1]);
//	else if (a > bigtemp[1] && a <= bigtemp[0])	bigtemp[1] = a;
//	else if (a >= bigtemp[0])
//	{
//		bigtemp[1] = bigtemp[0];
//		bigtemp[0] = a;
//	}
//	return;
//}
//
//
//
//int maxProfit(vector<int>& prices) {
//	if (prices.size() <= 1)return 0;
//	vector<int> res;
//	vector<int> bigtemp(2, 0);
//	vector<int> minindex;
//	vector<int> maxindex;
//	if (prices[1] >= prices[0]) minindex.push_back(0);
//	int mintemp = 0;
//	int maxtemp = 0;
//	int i = 1;
//	for (; i < prices.size();i++)
//	{
//		if (i < prices.size() - 1)
//		{
//			if (prices[i] <= prices[i - 1] && prices[i] <= prices[i + 1])
//			{
//				mintemp = i;
//				minindex.push_back(mintemp); //将所有的极小值点都放入minindex。
//			}
//			if (prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1])
//			{
//				maxtemp = i;
//				maxindex.push_back(maxtemp);
//
//				freshbigger(bigtemp, prices[maxtemp] - prices[mintemp]);
//				for (auto k : minindex)	freshbigger(bigtemp, prices[maxtemp] - prices[k]);
//				//minindex.clear(); //数组清0
//				mintemp = i;
//			}
//		}
//		else if (i == prices.size() - 1)
//		{
//			if(mintemp == maxtemp && prices[i] > prices[mintemp]) freshbigger(bigtemp, prices[i] - prices[mintemp]);
//			if(mintemp != maxtemp) freshbigger(bigtemp, prices[i] - prices[mintemp]);
//		}
//		
//
//	}
//	return res[0] + res[1];
//}
//
//
//
////int maxProfit1(vector<int>& prices, int &left, int & right,int start,int end) {
////	//设定窗口，最大值只可能出现在窗口中最大值最小值更新时。
////	int windowmin = prices[0];
////	int maxres = 0;
////	for (int i = start; i < end; i++)
////	{
////		if (prices[i] <= windowmin)
////		{
////			left = i;
////			windowmin = prices[i];
////		}
////		else if (prices[i] > windowmin)
////		{
////			if (prices[i] - windowmin > maxres) right = i;
////			maxres = max(maxres, prices[i] - windowmin);
////		}
////	}
////	return maxres;
////}
////
////
////int maxProfit(vector<int>& prices) {
////	if (prices.size() <= 1) return 0;
////	int left = 0;
////	int right = 0;
////	int res1 = maxProfit1(prices, left, right,0,prices.size());
////	int start = left;
////	int end = right;
////	int res2 = maxProfit1(prices, left, right, 0, start );
////	int res3 = maxProfit1(prices, left, right, end, prices.size());
////	return max(res1 + res2, res1 + res3);
////}
//
//
//
//int main()
//{
//	vector<int> input = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 };
//	cout << maxProfit(input);
//	system("Pause");
//	return 0;
//}