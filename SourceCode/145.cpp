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
//
////Way1: 先序遍历的迭代做法
////void Rec(TreeNode* root, vector<int> &res)
////{
////	if (!root) return;
////	if(root->left)Rec(root->left, res);
////	if(root->right)Rec(root->right, res);
////	res.push_back(root->val);
////	return;
////}
////
////
////vector<int> postorderTraversal(TreeNode* root) {
////	vector<int> res;
////	if (!root) return res;
////	Rec(root, res);
////	return res;
////}
//
////栈操作
//vector<int> postorderTraversal(TreeNode* root) {
//	vector<int> res;
//
//	if (!root) return res;
//
//	stack<TreeNode*> s1;
//	TreeNode* temp = root;
//	s1.push(temp);
//
//	while (!s1.empty()) {
//		temp = s1.top();
//		s1.pop();
//		//s2.push(temp);
//		res.push_back(temp->val);
//
//		if (temp->left) {
//			s1.push(temp->left);
//		}
//		if (temp->right) {
//			s1.push(temp->right);
//		}
//	}
//
//	reverse(res.begin(), res.end());
//	return res;
//}
