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
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//
////Way1: 使用dfs
//void dfs(TreeNode* root, string &processtring, int &totalsum)
//{
//	processtring = processtring + char(root->val + 48);
//	if (!root->left && !root->right)
//	{
//		totalsum += stoi(processtring);
//		return;   //终止条件
//	}
//	if (root->left)
//	{
//		dfs(root->left, processtring, totalsum);
//		processtring.pop_back();
//	}
//	if (root->right)
//	{
//		dfs(root->right, processtring, totalsum);
//		processtring.pop_back();
//	}
//	return;
//}
//
//
//int sumNumbers(TreeNode* root) {
//	if (!root) return 0;
//	string processstring;
//	int totalsum = 0;
//	dfs(root, processstring, totalsum);
//	return totalsum;
//}
//
//
//int main()
//{
//	TreeNode *T1 = new TreeNode(1);
//	TreeNode *T2 = new TreeNode(2);
//	TreeNode *T3 = new TreeNode(3);
//	T1->left = T2;
//	T1->right = T3;
//	cout << sumNumbers(T1) << endl;
//	system("Pause");
//	return 0;
//}