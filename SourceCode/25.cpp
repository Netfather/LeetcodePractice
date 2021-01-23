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

ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == NULL || head->next == NULL) return head;
	else if (k == 0 || k == 1) return head;
	else if (k > 1)
	{
		ListNode* ire = head->next;  //ָ��ǰ����λ��
		ListNode* temp = head; //�ݴ�
		ListNode* i = head; //�ݴ� ���������� ���ڷ���Kѭ����Χ������ǰ�������
		ListNode* tempNext;
		int count = 1; //
		ListNode* ArtificialHead = new ListNode(0); //�����ͷ
		//�������ͷ���ӵ�head��
		ArtificialHead->next = head;
		ListNode* ArtificialTail = new ListNode(0); //�����β
		ListNode* l = ArtificialHead; //�µ��� ά����
		ListNode* r = ArtificialHead; //�ϵ��� ά����
		ListNode* cur_l = ArtificialHead; //��ǰKѭ������µ��� ά����
		ListNode* cur_r = ArtificialHead; //��ǰKѭ������ϵ��� ά����
		//���� ������k֮��Ҫ����λ�ã����Ӧ����ȡ�����µ����Kѭ��������µ����ڽ���ѭ������
		while (i != NULL && count <= k)
		{
			if (count == 1)
			{
				l = cur_l;
				cur_l = i;
				temp = i; //������ѭ������ʼ��
				//save up boundries
			}
			if (count == 2) ire = i; //������ѭ���ĵڶ�����ʼ��
			if (count == k)
			{
				cur_r = i;
				r = i->next;
				i = cur_l;//��ʱά����Χ��ݹ����ʼ��
				count = 1;
				while (count < k)
				{
					tempNext = ire->next; //�洢��һ����ַ
					ire->next = temp;
					temp = ire;
					ire = tempNext;
					count++;
				}
				l->next = cur_r;
				cur_l->next = r;
				count = 0;
			}
			count++;
			i = i->next;
		}
		return ArtificialHead->next;
	}
	return NULL;
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

	res = reverseKGroup(l1, 2);
	return 0;
}

*/