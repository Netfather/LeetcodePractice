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
//class Node {
//public:
//	int val;
//	Node* next;
//	Node* random;
//
//	Node(int _val) {
//		val = _val;
//		next = NULL;
//		random = NULL;
//	}
//};
//
////Way1: 递归
////unordered_map<Node*, Node*> memo;
////
////Node* copyRandomList(Node* head) {
////	if (head == NULL) return NULL;
////	if (memo.count(head)) return memo[head];
////
////	Node* temp = new Node(head->val);
////	memo.insert(pair(head, temp));
////	temp->random = copyRandomList(head->random);
////	temp->next = copyRandomList(head->next);
////	return temp;
////}
//
////Way2: 遍历搜索
//Node* copyRandomList(Node* head) {
//	if (head == NULL) return NULL;
//	Node* copyHead = new Node(head->val);
//	queue<Node*> List;
//	queue<Node*> copyList;
//	unordered_map<Node*, Node*> memo;
//
//	List.push(head);
//	copyList.push(copyHead);
//
//	Node* temp = List.front();
//	Node* copytemp = copyList.front();
//	memo.insert(pair(temp, copytemp));
//
//	while (!List.empty())
//	{
//		temp = List.front();
//		copytemp = copyList.front();
//		if (temp->next)
//		{
//			if (!memo.count(temp->next)) //if not exist, build a new Node and push it into Que;
//			{
//				copytemp->next = new Node(temp->next->val);
//				memo.insert(pair(temp->next, copytemp->next));
//				List.push(temp->next);
//				copyList.push(copytemp->next);
//			}
//			else copytemp->next = memo[temp->next];
//		}
//		if (temp->random)
//		{
//			if (!memo.count(temp->random)) //if not exist, build a new Node and push it into Que;
//			{
//				copytemp->random = new Node(temp->random->val);
//				memo.insert(pair(temp->random, copytemp->random));
//				List.push(temp->random);
//				copyList.push(copytemp->random);
//			}
//			else copytemp->random = memo[temp->random];
//		}
//		List.pop();
//		copyList.pop();
//	}
//	return copyHead;
//}
//
//
//
