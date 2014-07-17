#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
		ListNode *swapPairs(ListNode *head)
		{
			ListNode ret(-1);
			ret.next = head;
			ListNode *pre = &ret;
			ListNode *cur = head;
			while(cur && cur->next)
			{
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;

				pre = cur;
				cur = cur->next;
			}
			return ret.next;
		}
};

/****** test code ***********************/
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
int main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	ListNode *list = makeList(a,sizeof(a)/sizeof(int));
	printList(list);
	Solution so;
	printList(so.swapPairs(list));
	return 0;
}
