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
		ListNode* ire = head->next;  //指向当前迭代位置
		ListNode* temp = head; //暂存
		ListNode* i = head; //暂存 自增迭代器 用于放在K循环外围进行提前挡板操作
		ListNode* tempNext;
		int count = 1; //
		ListNode* ArtificialHead = new ListNode(0); //人造表头
		//将人造表头连接到head上
		ArtificialHead->next = head;
		ListNode* ArtificialTail = new ListNode(0); //人造表尾
		ListNode* l = ArtificialHead; //下挡板 维护好
		ListNode* r = ArtificialHead; //上挡板 维护好
		ListNode* cur_l = ArtificialHead; //当前K循环里的下挡板 维护好
		ListNode* cur_r = ArtificialHead; //当前K循环里的上挡板 维护好
		//误区 由于在k之后要保留位置，因此应当先取得上下挡板和K循环里的上下挡板在进行循环操作
		while (i != NULL && count <= k)
		{
			if (count == 1)
			{
				l = cur_l;
				cur_l = i;
				temp = i; //单次内循环的起始点
				//save up boundries
			}
			if (count == 2) ire = i; //单次内循环的第二个起始点
			if (count == k)
			{
				cur_r = i;
				r = i->next;
				i = cur_l;//及时维护外围大递归的起始点
				count = 1;
				while (count < k)
				{
					tempNext = ire->next; //存储下一个地址
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