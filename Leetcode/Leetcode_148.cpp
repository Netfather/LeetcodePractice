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
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//
//void QuickSortList(ListNode* head, int end, ListNode* prehead)
//{
//	if (!head || end < 1) return;
//	int base = head->val; //基准值
//	ListNode* LeftIndex = prehead; //左延展基准值
//	ListNode* RightIndex = head;//右延展基准值
//	ListNode* ListIte = head->next;
//	ListNode* temp = head; //暂存
//	ListNode* preListIte = head;
//	int cnt = 0;
//	int small_base_loc = 0;
//	int large_base_loc = 0;
//	while (cnt < end && ListIte)
//	{
//		++cnt;
//		//左延展
//		if (ListIte->val < base)
//		{
//			preListIte->next = ListIte->next;
//			ListIte->next = LeftIndex->next;
//			LeftIndex->next = ListIte;
//			ListIte = preListIte->next;
//			++small_base_loc;
//		}
//		else if(ListIte->val > base)
//		{
//			RightIndex->next = ListIte;
//			RightIndex = ListIte;
//			ListIte = RightIndex->next;
//			preListIte = preListIte->next;
//			++large_base_loc;
//		}
//		else
//		{
//			temp = ListIte->next;
//			if (ListIte != head->next)
//			{
//				ListIte->next = head->next;
//				head->next = ListIte;
//				RightIndex->next = temp;
//			}
//			else
//			{
//				RightIndex = RightIndex->next;
//				preListIte = preListIte->next;
//			}
//			head = head->next;
//			ListIte = temp;
//		}
//	}
//	QuickSortList(LeftIndex->next, small_base_loc - 1, LeftIndex);
//	QuickSortList(head->next, large_base_loc-1 , head);
//}
//
//
////快速排序的链表版本  但是时间复杂度不达标 只能使用归并排序
//ListNode* sortList(ListNode* head) {
//	if (!head || !head->next) return head;
//	ListNode* Artificialhaed = new ListNode(INT_MIN);
//	Artificialhaed->next = head;
//	QuickSortList(head, INT_MAX, Artificialhaed);
//	return Artificialhaed->next;
//}
//
//
//int main()
//{
//	//ListNode* L1 = new ListNode(4);
//	//ListNode* L2 = new ListNode(4);
//	//ListNode* L3 = new ListNode(4);
//	//ListNode* L4 = new ListNode(4);
//	//ListNode* L5 = new ListNode(2);
//	//ListNode* L6 = new ListNode(2);
//	//ListNode* L7 = new ListNode(3);
//	//ListNode* L8 = new ListNode(1);
//	//ListNode* L9 = new ListNode(1);
//
//
//	//ListNode* L1 = new ListNode(7);
//	//ListNode* L2 = new ListNode(6);
//	//ListNode* L3 = new ListNode(3);
//	//ListNode* L4 = new ListNode(265);
//	//ListNode* L5 = new ListNode(7);
//	//ListNode* L6 = new ListNode(3);
//	//ListNode* L6 = new ListNode(6);
//	L1->next = L2;
//	L2->next = L3;
//	L3->next = L4;
//	L4->next = L5;
//	L5->next = L6;
//	sortList(L1);
//	system("Pause");
//	return 0;
//}