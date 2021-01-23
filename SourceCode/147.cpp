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
//
//};
//
//ListNode* insertionSortList(ListNode* head) {
//	if (!head) return head;
//	ListNode* Artificialhaed = new ListNode(INT_MIN);
//	Artificialhaed->next = head;
//	ListNode* InsertEnd = Artificialhaed; //插入循环停止位
//	if (!head->next) return head;
//	ListNode* temp = Artificialhaed->next; //迭代器
//	ListNode* InsertIre = Artificialhaed;
//	int flag = 0;
//	while (temp)
//	{
//		InsertEnd->next = NULL;
//		ListNode* InsertNode = temp;
//		InsertIre = Artificialhaed;
//		temp = temp->next;
//		ListNode* InsertPre = InsertIre;
//		while (InsertIre)
//		{
//			flag = 0;
//			if (InsertIre->val > InsertNode->val)
//			{
//				InsertPre->next = InsertNode;
//				InsertNode->next = InsertIre;
//				flag = 1;
//				break;
//			}
//			InsertPre = InsertIre;
//			InsertIre = InsertIre->next;
//		}
//		if (flag == 0)
//		{
//			InsertEnd->next = InsertNode;
//			InsertEnd = InsertNode;
//		}
//	}
//	return Artificialhaed->next;
//}
//
//int main()
//{
//	ListNode* L1 = new ListNode(-2147483647);
//	ListNode* L2 = new ListNode(INT_MIN);
//	L1->next = L2;
//	insertionSortList(L1);
//	system("Pause");
//	return 0;
//}