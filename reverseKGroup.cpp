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
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		ListNode ret(-1);
		ret.next = head;
		ListNode * cur = ret.next;
		ListNode * pre = &ret;
		while(testLongEnough(cur,k))
		{
			cur = reverseBetween(cur,1,k);
			pre->next = cur;
			for(int i=0; i<k; i++)
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return ret.next;
	}
private:
	bool testLongEnough(ListNode *head, int k)
	{
		ListNode ret(-1);
		ret.next = head;
		ListNode * cur = &ret;
		int i =0;
		for(i=0; cur && i<k; i++)
		{
			cur = cur->next;
		}
		return cur ? true : false;
	}
    ListNode *reverseBetween(ListNode *head, int m, int n)
	{
		ListNode ret(-1);
		ret.next = head;
		ListNode *pre = &ret;
		for(int i=1; i<m; i++)
			pre = pre->next;
		ListNode *sub_list = pre;
		pre = pre->next;
		for(int i=m; i<n; i++)
		{
			ListNode *tmp = pre->next;
			pre->next = pre->next->next;
			tmp->next = sub_list->next;
			sub_list->next = tmp;
		}
		return ret.next;
	}
};
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
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	ListNode *list = makeList(a, sizeof(a)/sizeof(int));
	printList(list);
	Solution so;
	printList(so.reverseKGroup(list,4));
	return 0;
}
