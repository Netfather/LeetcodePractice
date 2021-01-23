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
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};
//
////HahMap
////bool hasCycle(ListNode *head) {
////	unordered_set<ListNode*> memo;
////	ListNode *temp = head;
////	while (temp != NULL)
////	{
////		memo.insert(temp);
////		if (memo.count(temp->next)) return true;
////		temp = temp->next;
////	}
////	return false;
////}
//
////Two points: if there is circle, the points must be the same
//bool hasCycle(ListNode *head) {
//	if (head == NULL || head->next == NULL) return false;
//	ListNode *slow = head;
//	ListNode *fast = head->next;
//	while (slow != fast)
//	{
//		if (fast == NULL || fast->next == NULL) return false;
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return true;
//}