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
//vector<vector<int>> generate(int numRows) {
//	vector<vector<int>> res;
//	numRows++;
//	for (int i = 1; i < numRows; i++)
//	{
//		vector<int> tempres(i, 1);
//		res.push_back(tempres);
//		if (i != 1)	for (int j = 1; j < i - 1; j++)	res[i-1][j] = res[i -2][j - 1] + res[i - 2 ][j];
//	}
//	return res;
//}
//
//
//
//
//int main()
//{
//	vector<vector<int>> res;
//	res = generate(2);
//	for (auto i : res)
//	{
//		for(auto j :i)
//		{
//			cout << j << "  ";
//		}
//		cout << endl;
//	}
//	system("Pause");
//	return 0;
//}