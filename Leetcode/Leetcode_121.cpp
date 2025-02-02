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
//
//int maxProfit(vector<int>& prices) {
//	if (prices.size() <= 1) return 0;
//	//设定窗口，最大值只可能出现在窗口中最大值最小值更新时。
//	int windowmin = prices[0];
//	int maxres = 0;
//
//	for (int i = 1; i < prices.size(); i++)
//	{
//		if (prices[i] <= windowmin) windowmin = prices[i];
//		else if (prices[i] > windowmin) maxres = max(maxres, prices[i] - windowmin);
//	}
//	return maxres;
//}
//
//
//
//
//
//int main()
//{
//	vector<int> input = { 2,4,1 };
//	cout << maxProfit(input);
//	cout << endl;
//	system("Pause");
//	return 0;
//}
