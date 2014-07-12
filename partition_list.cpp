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
		ListNode * partition(ListNode *head, int x)
		{
			ListNode ret_L(-1);
			ListNode ret_R(-1);
			ListNode *cur_L = &ret_L;
			ListNode *cur_R = &ret_R;
			for(ListNode *cur=head; cur; cur=cur->next)
			{
				if(cur->val < x)
				{
					cur_L->next = cur;
					cur_L = cur_L->next;
				}
				else
				{
					cur_R->next = cur;
					cur_R = cur_R->next;
				}
			}
			cur_L->next = ret_R.next;
			cur_R->next = 0;
			return ret_L.next;
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
	int a[] = {1,2,3,4,5,6,7,8,9,10};//{10,9,8,7,6,5,4,3,2,1};
	ListNode *list = makeList(a, sizeof(a)/sizeof(int));
	printList(list);
	Solution so;
	printList(so.partition(list,3));
}
