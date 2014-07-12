#include <iostream>
using namespace std;
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
			while(cur_L1 || cur_L2)
			{
				int val_1 = cur_L1 ? cur_L1->val : 0;
				int val_2 = cur_L2 ? cur_L2->val : 0;
				int sum = carry + val_1 + val_2;
				carry = sum>=10 ? 1 : 0;
				cur_ret->next = new ListNode(sum%10);
				cur_ret = cur_ret->next;
				cur_L1 = cur_L1 ? cur_L1->next : 0;
				cur_L2 = cur_L2 ? cur_L2->next : 0;
			}
			if(carry)
			{
				cur_ret->next = new ListNode(1);
			}
			return ret.next;
		}
};
void printList(ListNode *list)
{
	ListNode * cur = list;
	while(cur)
	{
		cout<<cur->val<<"->";
		cur = cur->next;
	}
	cout<<"null"<<endl;
}

ListNode *makeList(int val[], int n)
{
	ListNode ret(-1);
	ListNode *tmp;
	for(int i=0; i<n; i++)
	{
		tmp = new ListNode(val[i]);
		tmp->next = ret.next;
		ret.next = tmp;
	}
	return ret.next;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int b[] = {9,8,7,6,5,4,3,2};
	ListNode *list_1 = makeList(a,sizeof(a)/sizeof(int));
	ListNode *list_2 = makeList(b,sizeof(b)/sizeof(int));
	printList(list_1);
	printList(list_2);
	Solution so;
	ListNode *ret = so.addTwoNumbers(list_1, list_2);
	printList(ret);
	return 1;
}
