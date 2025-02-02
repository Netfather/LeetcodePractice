
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
return start;
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
return start;
}
l1 = l1->next;
}
}
l1->next = l2;
return start;
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* res;
	vector<int> ire;
	int i = 0;
	if (lists.size() == 0) return res;
	if (lists.size() == 1) return lists[0];
	if (lists.size() > 1)
	{
		for (i = 0; i < lists.size(); i++)
		{
			res = mergeTwoLists(res, lists[i]);
		}
		return res;
	}
	return res;

}


int main()
{



	return 0;
}


*/