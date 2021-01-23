//
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
//vector<int> generate(int numRows) {
//	vector<int> res;
//	for (int i = 1; i < numRows+2; i++)
//	{
//		vector<int> tempres(i, 1);
//		if (i != 1)	for (int j = 1; j < i - 1; j++)	tempres[j] = res[j - 1] + res[j];
//		res = tempres;
//	}
//	return res;
//}
//
//
//int main()
//{
//	vector<int> res;
//	res = generate(1);
//	for (auto i : res)
//	{
//
//		cout << i << "  ";
//
//	}
//	system("Pause");
//	return 0;
//}