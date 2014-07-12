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
		ListNode *deleteDuplicates(ListNode *head)
		{
			ListNode *cur = head;
			while(cur && cur->next)
			{
				if(cur->next->val == cur->val)
				{
					ListNode *del = cur->next;
					cur->next = cur->next->next;
					delete del;
				}
				else
					cur = cur->next;
			}
			return head;
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
	int a[] = {1,1,1,2,2,3};
	ListNode *list = makeList(a,sizeof(a)/sizeof(int));
	printList(list);
	Solution so;
	printList(so.deleteDuplicates(list));
	return 0;
}
