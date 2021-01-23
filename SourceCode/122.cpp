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
//int maxProfit(vector<int>& prices) {
//	if (prices.size() <= 1)return 0;
//	int res = 0;
//	for (int i = 1; i < prices.size(); ++i) {
//		if (prices[i] > prices[i - 1]) {
//			res += prices[i] - prices[i - 1];
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> input = { 1,3,2,5,6,10,5,8 };
//	cout << maxProfit(input);
//	system("Pause");
//	return 0;
//}