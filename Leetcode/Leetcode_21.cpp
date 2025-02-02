
/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* start;
	ListNode* temp; //用于存储当前待连接位置
	ListNode* follow; //用于跟随已经构建完成的部分
	if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;
	else if (l1->next == NULL && l2->next == NULL)
	{
		if (l1->val <= l2->val)
		{
			l1->next = l2;
			return l1;
		}
		else if (l1->val > l2->val)
		{
			l2->next = l1;
			return l2;
		}
	}
	else if (l1->next == NULL && l2->next != NULL)
	{
		if (l1->val <= l2->val)
		{
			l1->next = l2;
			return l1;
		}
		else if (l1->val > l2->val)
		{
			start = l2;
			while (l2->next != NULL)
			{
				if (l2->val <= l1->val && l2->next->val > l1->val)
				{
					l1->next = l2->next;
					l2->next = l1;
					return l2;
				}
				l2 = l2->next;
			}
		}
		l2->next = l1;
		return start;
	}
	else if (l2->next == NULL && l1->next != NULL)
	{
		if (l2->val <= l1->val)
		{
			l2->next = l1;
			return l2;
		}
		else if (l2->val > l1->val)
		{
			start = l1;
			while (l1->next != NULL)
			{
				if (l1->val <= l2->val && l1->next->val > l2->val)
				{
					l2->next = l1->next;
					l1->next = l2;
					return l1;
				}
				l1 = l1->next;
			}
		}
		l1->next = l2;
		return l1;
	}
	else if (l1->next != NULL && l2->next != NULL)
	{
		if (l1->val > l2->val)
		{
			temp = l2;
			l2 = l1;
			l1 = temp;
		}
		start = l1;

		while (l1->next != NULL && l2->next != NULL)
		{
			if (l1->val <= l2->val)
			{

				if (l1->next->val < l2->val)
				{
					l1 = l1->next;
				}
				else if (l1->next->val >= l2->val)
				{
					temp = l2;
					l2 = l2->next;
					temp->next = l1->next;
					l1->next = temp;
					l1 = l1->next;
				}
			}
		}
		if (l2->next == NULL)
		{
			while (l1->next != NULL)
			{
				if (l1->val <= l2->val && l1->next->val >= l2->val)
				{
					l2->next = l1->next;
					l1->next = l2;
					return start;
				}
				l1 = l1->next;
			}
			l1->next = l2;
			return start;
		}
		if (l1->next == NULL) l1->next = l2;
		return start;
	}
	return NULL;

}
way2  wasted
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
if (l1 == NULL) return l2;
if (l2 == NULL) return l1;
ListNode* ire1 = l1;
ListNode* ire2 = l2;
ListNode* temp;
ListNode* res;
ListNode* resf;
if (ire1->val <= ire2->val)
{
temp = new ListNode(ire1->val); //存储当前要改变的结点
ire1 = ire1->next;
}
else if (ire1->val > ire2->val)
{
temp = new ListNode(ire2->val);
ire2 = ire2->next;

}
resf = temp;
//定义两个迭代器

//赋予两个链表的首字节
while (ire1 != NULL && ire2 != NULL)
{
if (ire1->val <= ire2->val)
{
res = new ListNode(ire1->val);
ire1 = ire1->next;
}
else if (ire1->val > ire2->val)
{
res = new ListNode(ire2->val);
ire2 = ire2->next;
}
temp->next = res;
temp = temp->next;
}
if (ire1 == NULL)	temp->next = ire2;
if (ire2 == NULL)	temp->next = ire1;
return resf;
}




int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l12 = new ListNode(3);
	ListNode* l13 = new ListNode(4);
//	l1->next = l12;
//	l12->next = l13;

	ListNode* l2 = new ListNode(2);
	ListNode* l22 = new ListNode(2);
	ListNode* l23 = new ListNode(4);
//	l2->next = l22;
//	l22->next = l23;

	ListNode*res = mergeTwoLists(l1, l2);
	system("Pause");
	return 0;
}

*/
