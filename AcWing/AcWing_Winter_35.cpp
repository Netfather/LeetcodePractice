//˼·��

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <climits>
using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 

//������

    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* cur = head->next;
        ListNode* pre = head;
        while (cur != NULL)
        {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next = NULL;
        return pre;
    }

// �ݹ鷨
    // �ݹ�����Ҫ�ľ���Ҫ�����׵ݹ龿������ʲô �ݹ���Ҫ��ʲô
    // ����� �ݹ����������һ�������ķ�ת�б����
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;  //��ֹ���� ���Ϊ�� ��ô�ͷ��ؿ�
        if (!head->next) return head; // ���ֻ��һ���� ��ô��ֱ�ӷ�����һ��

        ListNode* tail = reverseList(head->next);
        head->next->next = head;   // ������ڵ����һ��ָ���Լ� Ȼ���Լ�ָ��NULL
        head->next = NULL;
        return tail;
    }


int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    ListNode* p = reverseList(l1);
    return 0;


}