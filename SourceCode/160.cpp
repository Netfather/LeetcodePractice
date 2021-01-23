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
//struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
// 
//
//
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//	if (!headA || !headB) return NULL;
//	//Step1: Find tail
//	ListNode* temp = headA;
//	while (temp->next) temp = temp->next;
//	//Step2: Draw a circle
//	temp->next = headB;
//	//Step3: find circle position
//	ListNode* fast = headA->next;
//	ListNode* slow = headA;
//	while (fast != slow)
//	{
//		if (fast == NULL || fast->next == NULL)
//		{
//			temp->next = NULL;  //Maintain
//			return NULL;
//		}
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	fast = fast->next;
//	while (headA && fast)
//	{
//		if (headA == fast) break;
//		headA = headA->next;
//		fast = fast->next;
//	}
//	temp->next = NULL; //Maintain
//	return fast;
//}