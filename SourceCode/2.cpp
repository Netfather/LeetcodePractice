//算法笔记，这道题主要考察链表的构建和调用，赋值，重新构建

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *temp;
	//read l1
	int a[100];
	int length1 = 1;
	a[0] = l1->val;
	temp = l1->next;
	if (temp != NULL)
	{
		for (int i = 1;; i++)
		{
			a[i] = temp->val;
			if (temp->next == NULL)
			{
				length1 = i + 1;
				break;
			}
			temp = temp->next;
		}
	}
	//read l2
	int b[100];
	int length2 = 1;
	b[0] = l2->val;
	temp = l2->next;
	if (temp != NULL)
	{
		for (int i = 1;; i++)
		{
			b[i] = temp->val;
			if (temp->next == NULL)
			{
				length2 = i + 1;
				break;
			}
			temp = temp->next;
		}
	}
	//add
	int switchint = 0;
	int c[101];
	c[0] = 10; //为避免溢出
	int flag = 0; //进位数据，又循环维护 极其重要
	if (length1 <= length2)  //交换数据 必须要对位
	{
		switchint = length1;
		length1 = length2;
		length2 = switchint;
		for (int i = 0; i < length1; i++)
		{
			switchint = a[i];
			a[i] = b[i];
			b[i] = switchint;
		}
	}
	for (int i = 0; i < length2; i++)
	{
		c[i] = (a[i] + b[i] + flag) % 10;
		//进位维护 极其重要
		if ((a[i] + b[i] + flag) > 9) flag = 1;
		if ((a[i] + b[i] + flag) < 10) flag = 0;
	}
	for (int i = length2; i < length1; i++)
	{
		c[i] = (a[i] + flag) % 10;
		//进位维护 极其重要
		if ((a[i] + flag) > 9) flag = 1;
		if ((a[i] + flag) < 10) flag = 0;
	}
	//经过上面的两个循环之后，如果循环位不为0则需要额外进位
	if (flag == 1)
	{
		c[length1] = 1;
		c[length1 + 1] = 10; //10表示到头了
	}
	else
	{
		c[length1] = 10; //10表示到头了
	}
	flag = 0; //进位维护
	int flagres = 0; //统计结果的位数
	for (int i = 0;; i++)
	{
		if (c[i] != 10) flagres++;
		if (c[i] == 10) break;
	}
	//此时所有需要的结果都已经在数组c中，标志位为10，遇到10直接NULL就可以
	ListNode *result = new ListNode(c[0]);
	ListNode *restemp = new ListNode(0);  //维护目前链表构建到哪里了，极其重要，在循环中维护
	restemp = result;
	for (int i = 1; i < flagres; i++)
	{
		ListNode *kk = new ListNode(c[i]);
		restemp->next = kk;
		restemp = restemp->next;
	}
	return result;
}

int main()
{
	//示范如何将数据加入Node的后面
	ListNode l1add1(9), l1add2(9);
	ListNode l2add1(9), l2add2(9);
	ListNode l1(9);
	ListNode l2(9);
	ListNode *temp;

	l1add1.next = &l1add2;
	l2add1.next = &l2add2;

	l1.next = &l1add1;
	l2.next = &l2add1;
//	lres.next = &add;
//	add.next = &add2;
	//示范如何读出完整一条数据链表
	addTwoNumbers(&l1, &l2);
	system("Pause");
	return 0;
}

/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode lres(0);
		ListNode temp(0);
		* temp = l1->next;


	}
};

*/