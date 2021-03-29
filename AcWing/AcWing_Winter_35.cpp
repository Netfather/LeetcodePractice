//思路：

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
 

//迭代法

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

// 递归法
    // 递归最重要的就是要想明白递归究竟返回什么 递归中要做什么
    // 这道题 递归就让他返回一个完整的反转列表因此
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;  //终止条件 如果为空 那么就返回空
        if (!head->next) return head; // 如果只有一个了 那么就直接返回这一个

        ListNode* tail = reverseList(head->next);
        head->next->next = head;   // 将输入节点的下一个指向自己 然后自己指向NULL
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