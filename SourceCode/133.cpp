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
//// Definition for a Node.
//class Node {
//public:
//	int val;
//	vector<Node*> neighbors;
//
//	Node() {
//		val = 0;
//		neighbors = vector<Node*>();
//	}
//
//	Node(int _val) {
//		val = _val;
//		neighbors = vector<Node*>();
//	}
//
//	Node(int _val, vector<Node*> _neighbors) {
//		val = _val;
//		neighbors = _neighbors;
//	}
//};
//
////Way1 老老实实递归他不香么？ 不好意思由于循环图的存在，递归也不行，只能通过一个存储映射表格来反馈
//
////Node* cloneGraph(Node* node) {
////	if (!node) return NULL;
////	queue<Node*> Que;
////	queue<Node*> clone_Que;
////	unordered_map<Node*,int> org_set; //存储原始每个节点地址数据的hashmap
////	unordered_map<Node*,int> clone_set; //存储原始每个节点地址数据的hashmap
////	Node* clonehead = new Node(node->val);
////	Node* clonenode = clonehead;
////
////	Que.push(node);  //Intialize
////	clone_Que.push(clonenode);  //Intialize
////	int cnt = 0;
////
////	org_set.insert(pair(node, cnt));
////	clone_set.insert(pair(clonenode, cnt));
////	++cnt;
////
////	while (!Que.empty() )
////	{
////		Node* temp = Que.front();
////		Node* clone_temp = clone_Que.front();
////		if (temp->neighbors.size() != 0)
////		{
////			for (int i = 0; i < temp->neighbors.size();i++)
////			{
////				if (!org_set.count(temp->neighbors[i]))
////				{
////					clone_temp->neighbors.push_back(new Node((temp->neighbors[i])->val));
////					org_set.insert(pair(temp->neighbors[i], cnt));
////					clone_set.insert(pair(clone_temp->neighbors.back(), cnt));
////					++cnt;
////					Que.push(temp->neighbors[i]);
////					clone_Que.push(clone_temp->neighbors[i]);
////				}
////				else
////				{
////					for (auto &n : clone_set)
////					{
////						if (n.second == org_set[temp->neighbors[i]])
////						{
////							clone_temp->neighbors.push_back(n.first);
////							break;
////						}
////					}
////				}
////			}
////		}
////		Que.pop();
////		clone_Que.pop();
////	}
////	return clonehead;
////}
//
////改进版
//Node* cloneGraph(Node* node) {
//		if (!node) return NULL;
//		queue<Node*> Que;
//		queue<Node*> clone_Que;
//		unordered_map<Node*,Node*> Refle_map; //存储原始每个节点地址数据的hashmap
//		//unordered_map<Node*,int> clone_set; //存储原始每个节点地址数据的hashmap
//		Node* clonehead = new Node(node->val);
//		Node* clonenode = clonehead;
//	
//		Que.push(node);  //Intialize
//		clone_Que.push(clonenode);  //Intialize
//	
//		Refle_map.insert(pair(node, clonenode));
//	
//		while (!Que.empty() )
//		{
//			Node* temp = Que.front();
//			Node* clone_temp = clone_Que.front();
//			if (temp->neighbors.size() != 0)
//			{
//				for (int i = 0; i < temp->neighbors.size();i++)
//				{
//					if (!Refle_map.count(temp->neighbors[i]))
//					{
//						clone_temp->neighbors.push_back(new Node((temp->neighbors[i])->val));
//						Refle_map.insert(pair(temp->neighbors[i], clone_temp->neighbors.back()));
//						Que.push(temp->neighbors[i]);
//						clone_Que.push(clone_temp->neighbors[i]);
//					}
//					else clone_temp->neighbors.push_back(Refle_map[temp->neighbors[i]]);
//				}
//			}
//			Que.pop();
//			clone_Que.pop();
//		}
//		return clonehead;
//	}
//
//
////////Way 2 递归
////unordered_map<Node*, Node*> memo;
////Node* cloneGraph(Node* node) {
////	if (node == NULL) return NULL;
////	if (memo.count(node)) return memo[node];
////	Node* temp = new Node(node->val);
////	memo.insert(pair(node, temp));
////	//if (node->neighbors.empty()) return temp;
////	for (int i = 0; i < node->neighbors.size(); i++)
////	{
////		temp->neighbors.push_back(cloneGraph(node->neighbors[i]));
////	}
////	return temp;
////}
//
//int main()
//{
//	Node *T1 = new Node(1);
//	Node *T2 = new Node(2);
//	Node *T3 = new Node(3);
//	Node *T4 = new Node(4);
//	T1->neighbors.push_back(T2);
//	T1->neighbors.push_back(T4);
//
//	T2->neighbors.push_back(T1);
//	T2->neighbors.push_back(T3);
//
//	T3->neighbors.push_back(T2);
//	T3->neighbors.push_back(T4);
//
//	T4->neighbors.push_back(T1);
//	T4->neighbors.push_back(T3);
//
//	Node *cloneroot = cloneGraph(T1);
//	system("Pause");
//
//	return 0;
//}
//
