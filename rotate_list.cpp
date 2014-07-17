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
		ListNode *rotateRight(ListNode *head, int k)
		{
			if(!head) return head;
			ListNode *cur = head;
			int i = 1;
			while(cur->next)
			{
				cur = cur->next;
				i++;
			}
			cur->next = head;
			for(int j=0; j<i-(k%i); j++)
			{
				cur = cur->next;
			}
			head = cur->next;
			cur->next = 0;
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
	int a[] = {1,2,3,4,5,6,7,8};
	ListNode *list = makeList(a,sizeof(a)/sizeof(int));
	printList(list);
	Solution so;
	printList(so.rotateRight(list,2));
	return 0;
}
