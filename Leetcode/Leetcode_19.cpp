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
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* temp;
	if (head->next == NULL) return temp;
	vector<int> nums;
	temp = head;
	while (temp != NULL)
	{
		nums.push_back(temp->val);
		temp = temp->next;
	}
	nums.erase(nums.end() - n);

	ListNode *output = new ListNode(nums[0]);
	ListNode *outhead;
	ListNode *before;
	before = output;
	if (nums.size() > 1)
	{
		for (int i = 1; i< nums.size();i++)
		{
			ListNode *temp_out = new ListNode(nums[i]);
			before->next = temp_out;
			before = before->next;
		}
	}
	return output;

}


int main()
{
	ListNode input(1);
	ListNode *head;
	ListNode *before;
	head = &input;
	before = head;
	for (int i = 2; i < 6; i++)
	{
		ListNode *temp = new ListNode(i) ;
		before->next = temp;
		before =before -> next;
	}
	head = removeNthFromEnd(head, 2);
	system("Pause");
	return 0;
}


*/