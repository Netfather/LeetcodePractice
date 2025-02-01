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
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *next) : val(x), next(next) {}
//	
//};
//
//void reorderList(ListNode* head) {
//	//Step1:得到这个list的长度 No,用两个长短不一的指针直接得到
//	stack<ListNode*> table; //记录slow走过的节点
//	if (!head || !head->next || !head->next->next) return;
//	ListNode* fast = head->next;
//	ListNode* slow = head;
//	int flag = 0; //0为偶数 1为奇数
//	while (fast && fast->next)
//	{
//		if (fast->next->next) fast = fast->next->next;
//		else { fast = fast->next; flag = 1; }
//		table.push(slow);
//		slow = slow->next;
//	}
//	table.push(slow);
//	slow = slow->next;
//	ListNode* rightTemp = slow->next;
//	ListNode *leftTemp = table.top()->next;
//	int cnt = 0;
//	while (!table.empty())
//	{
//		if (flag == 0)
//		{
//			if (cnt == 0) { slow->next = NULL; slow = rightTemp; }
//			else
//			{
//				rightTemp = slow->next;
//				leftTemp = table.top()->next;
//				table.top()->next = slow;
//				slow->next = leftTemp;
//				slow = rightTemp;
//			}
//		}
//		else
//		{
//			if (cnt == 0)
//			{
//				table.top()->next = NULL;
//				leftTemp = table.top();
//			}
//			else
//			{
//				rightTemp = slow->next;
//				table.top()->next = slow;
//				slow->next = leftTemp;
//				slow = rightTemp;
//				leftTemp = table.top();
//			}
//		}
//		table.pop();
//		++cnt;
//	}
//	return;
//}
//
//
//int main()
//{
//	ListNode *L1 = new ListNode(1);
//	ListNode *L2 = new ListNode(2);
//	ListNode *L3 = new ListNode(3);
//	ListNode *L4 = new ListNode(4);
//	ListNode *L5 = new ListNode(5);
//	L1->next = L2;
//	L2->next = L3;
//	L3->next = L4;
//	L4->next = L5;
//	reorderList(L1);
//
//	system("Pause");
//	return 0;
//}