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
///*
//void Rec(TreeNode* root, int &sum, int cnt, vector<vector<int>> &res, vector<int> &tempres)
//{
//	if (root == NULL) return;
//	cnt = cnt + root->val;
//	tempres.push_back(root->val);
//	if (root->left == NULL && root->right == NULL)	if (cnt == sum)	res.push_back(tempres);
//	Rec(root->left, sum, cnt, res, tempres);
//	Rec(root->right, sum, cnt, res, tempres);
//	tempres.pop_back();
//	cnt = cnt - root->val;
//	return;
//}
//*/
//
////这道题需要转变思维，我们需要站在最后一行往上看，那么从顶向下的更新这个表格，然后站在最后一层，看上一层，谁最小我就选谁即可得到最后的结果。
//void Rec(int &mintemp, int i_zong, vector<vector<int>>& triangle)
//{
//	if (i_zong == triangle.size()) return;
//	mintemp = INT_MAX;
//	//最左边只可能由上一层的最左边过来
//	triangle[i_zong][0] += triangle[i_zong - 1][0];
//	mintemp = min(mintemp, triangle[i_zong][0]);
//	//最右边只可能由上一层的最后边过来
//	int j_heng = triangle[i_zong].size();
//	triangle[i_zong][j_heng-1] += triangle[i_zong - 1][j_heng -2];
//	mintemp = min(mintemp, triangle[i_zong][j_heng - 1]);
//	//对当前这一“最后一行”，遍历每一个元素，对每个元素做出最佳选择即可
//	for (int m = 1; m < j_heng - 1; m++)
//	{
//		triangle[i_zong][m] += min(triangle[i_zong - 1][m], triangle[i_zong - 1][m - 1]);
//		mintemp = min(mintemp, triangle[i_zong][m]);
//	}
//	Rec(mintemp, i_zong + 1, triangle);
//	return;
//}
//
//
//int minimumTotal(vector<vector<int>>& triangle) {
//	int mintemp = INT_MAX;
//	if (triangle.empty()) return 0;
//	if (triangle.size() == 1) return triangle[0][0];
//	Rec(mintemp, 1, triangle);
//	return mintemp;
//}
//
//int main()
//{
//	vector<vector<int>> input =
//	{
//		{2},{3,4},{6,5,7},{4,1,8,3}
//	};
//
//	int res = minimumTotal(input);
//	cout << res << endl;
//	system("Pause");
//
//
//	return 0;
//}
//
