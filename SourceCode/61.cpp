
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

ListNode* rotateRight(ListNode* head, int k) {

	//Step 1: ����һ���ҵ�List�ĳ��Ⱥ��������Ԫ�ص���ʼλ��
	ListNode *temp = head;
	ListNode *last = head;
	ListNode *prelast = head;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		prelast = last;
		last = temp;
		temp = temp->next;
	}
	if (length == 1) return head;
	
	ListNode *prehead = new ListNode(0); //�����ͷ
	prehead->next = head; //���������ͷ

	//Step 2: ����k���ж���Ҫ���ж��ٴα仯
	k = k % length;
	if (k == 0) return head;
	for (int i = 0; i < k; i++)
	{
		//Step 1: �޸�λ��
		prehead->next = last;
		last->next = head;
		prelast->next = NULL;
		//Step 2: ��ԭλ��
		head = last;
		last = prelast;
		//Step 3: í��prelastλ��
		temp = head;
		int cnt = 1;
		while (temp != NULL)
		{
			cnt = cnt + 1;
			if (cnt == length ) break;
			temp = temp->next;
		}
		prelast = temp;
	}
	return prehead->next;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *lone = new ListNode(2);
	ListNode *ltwo = new ListNode(3);
	ListNode *lthree = new ListNode(4);

	head->next = lone;
	lone->next = ltwo;
	ltwo->next = lthree;

	ListNode *res;
	res = rotateRight(head, 4);

	ListNode *temp = res;
	while (temp != NULL)
	{
		cout << temp->val << "  ";
		temp = temp->next;
	}
	system("Pause");



	return 0;
}

*/