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
////�������Ҫת��˼ά��������Ҫվ�����һ�����Ͽ�����ô�Ӷ����µĸ���������Ȼ��վ�����һ�㣬����һ�㣬˭��С�Ҿ�ѡ˭���ɵõ����Ľ����
//void Rec(int &mintemp, int i_zong, vector<vector<int>>& triangle)
//{
//	if (i_zong == triangle.size()) return;
//	mintemp = INT_MAX;
//	//�����ֻ��������һ�������߹���
//	triangle[i_zong][0] += triangle[i_zong - 1][0];
//	mintemp = min(mintemp, triangle[i_zong][0]);
//	//���ұ�ֻ��������һ������߹���
//	int j_heng = triangle[i_zong].size();
//	triangle[i_zong][j_heng-1] += triangle[i_zong - 1][j_heng -2];
//	mintemp = min(mintemp, triangle[i_zong][j_heng - 1]);
//	//�Ե�ǰ��һ�����һ�С�������ÿһ��Ԫ�أ���ÿ��Ԫ���������ѡ�񼴿�
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
