//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//
//int maxPoints(vector<vector<int>>& points) {
//	//锚定一个基准点，计算所有与这个基准点的斜率，计算完成即可得到过这个点的最大值
//	if (points.empty()) return 0;
//	if (points.size() == 1) return 1;
//	if (points.size() == 2) return 2;
//	map<double, int> memo_k;
//	int res = 2;
//	while (points.size() > 2)
//	{
//		int vertical_cnt = 1;
//		int base_x = points[points.size() - 1][0];
//		int base_y = points[points.size() - 1][1];
//		memo_k.clear();
//		int tempres = 0;
//		int same_points = 0;
//		for (int i = points.size() - 2; i >= 0; i--)
//		{
//			if (points[i][0] == base_x && points[i][1] != base_y) ++vertical_cnt;
//			else if (points[i][0] == base_x && points[i][1] == base_y)
//			{
//				++same_points;
//				points.erase(points.begin() + i);
//			}
//			else
//			{
//				double k = ((double)(points[i][1] - base_y) / (points[i][0] - base_x));
//				++memo_k[k];
//			}
//		}
//		for (auto &i : memo_k) if (++i.second > tempres) tempres = i.second;
//		tempres = (tempres > vertical_cnt ? tempres : vertical_cnt) + same_points;
//		res = max(res, tempres);
//		points.pop_back();
//	}
//	return res;
//}
//
//int main()
//{
//	vector<vector<int>> points = { {21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29} };
//	cout << maxPoints(points) <<endl;
//	system("Pause");
//	return 0;
//}