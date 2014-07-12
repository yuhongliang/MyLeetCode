#include <iostream>
 //Definition for singly-linked list.
struct ListNode 
{
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
	public:
	    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
		{
			ListNode *cur_L1 = l1;
			ListNode *cur_L2 = l2;
			ListNode ret(-1);
			ListNode *cur_ret = &ret;
			int carry = 0;
			while(cur_L1 && cur_L2)
			{
				int sum = carry + cur_L1->val + cur_L2->val;
				carry = sum>=10 ? 1 : 0;
				cur_ret->next = new ListNode(sumi%10);
				cur_ret = cur_ret->next;
			}
			cur_ret->next = cur_L1 ? cur_L1 : cur_L2;
		}
};
