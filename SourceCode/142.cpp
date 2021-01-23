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
////ListNode *detectCycle(ListNode *head) {
////	unordered_set<ListNode*> memo;
////	ListNode *temp = head;
////	while (temp != NULL)
////	{
////		memo.insert(temp);
////		if (memo.count(temp->next)) return temp->next;
////		temp = temp->next;
////	}
////	return NULL;
////}
//
////Two points: if there is circle, the points must be the same
//ListNode *detectCycle(ListNode *head) {
//	if (head == NULL || head->next == NULL) return NULL;
//	ListNode *slow = head;
//	ListNode *fast = head->next;
//	ListNode *crack = head;
//	int time_clock = 0;
//	while (slow != fast)
//	{
//		++time_clock;
//		if (fast == NULL || fast->next == NULL) return NULL;
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	if (time_clock == 0) return fast;
//	fast = fast->next;
//	while (crack && fast)
//	{
//		if (crack == fast) return crack;
//		crack = crack->next;
//		fast = fast->next;
//	}
//	return NULL;
//}
//
//int main()
//{
//	ListNode *L1 = new ListNode(1);
//	ListNode *L2 = new ListNode(2);
//	ListNode *L3 = new ListNode(3);
//	ListNode *L4 = new ListNode(4);
//	L1->next = L2;
//	L2->next = L3;
//	L3->next = L4;
//	L4->next = L2;
//	detectCycle(L1);
//
//	system("Pause");
//	return 0;
//}