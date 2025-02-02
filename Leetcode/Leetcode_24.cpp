
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

ListNode* swapPairs(ListNode* head) {
	ListNode* start = head;
	ListNode* temp = head;
	ListNode* temp_b = new ListNode(0);
	ListNode* temp_f; //暂存除了这两个的第三个元素
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	ListNode* headNext = head->next; //暂存第二个数据
	start = head->next;
	if (headNext->next == NULL)
	{
		temp = headNext;
		head->next = NULL;
		temp->next = head;
		return temp;
	}
	if (headNext->next != NULL)
	{
		while (headNext->next != NULL)
		{
			temp_b->next = headNext;
			temp_f = headNext->next;
			head->next = temp_f;
			headNext->next = head;
			temp = headNext;
			headNext = head;
			head = temp;
			headNext = headNext->next;
			head = head->next;
			if (headNext->next == NULL)
			{
				return start;
			}
			temp = head;
			temp_b = head;
			head = head->next;
			headNext = headNext->next;
		}
		temp->next = headNext;
		head->next = NULL;
		headNext->next = head;
		return start;
	}
	return start;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l12 = new ListNode(2);
	ListNode* l13 = new ListNode(3);
	ListNode* l14 = new ListNode(4);
	ListNode* l15 = new ListNode(5);
	l1->next = l12;
	l12->next = l13;
	l13->next = l14;
	l14->next = l15;
	ListNode* res;
	res = swapPairs(l1);

	system("Pause");


	return 0;
}

*/