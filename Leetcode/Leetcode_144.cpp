//#include <iostream>
//#include <algorithm>
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
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//
//};
//
////Way1: 先序遍历的迭代做法
////void Rec(TreeNode* root, vector<int> &res)
////{
////	if (!root) return;
////	res.push_back(root->val);
////	if(root->left)Rec(root->left, res);
////	if(root->right)Rec(root->right, res);
////	return;
////}
////
////vector<int> preorderTraversal(TreeNode* root) {
////	vector<int> res;
////	if (!root) return res;
////	Rec(root, res);
////	return res;
////}
//
//
//vector<int> preorderTraversal(TreeNode* root) {
//	stack<TreeNode*> Stack;
//	vector<int> res;
//	if (!root) return res;
//	TreeNode* temp = root;
//	while (!Stack.empty() || temp)
//	{
//		while (temp)
//		{
//			res.push_back(temp->val);
//			Stack.push(temp);
//			temp = temp->left;
//		}
//		temp = Stack.top();
//		temp = temp->right;
//		Stack.pop();
//	}
//	return res;
//}
