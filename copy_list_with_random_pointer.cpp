#include <iostream>
using namespace std;


//  Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution 
{
    public:
	    RandomListNode *copyRandomList(RandomListNode *head) 
	    {
		RandomListNode *cur = head;
		RandomListNode *new_node;
		while(cur)
		{
		    new_node = new RandomListNode(cur->label);
		    new_node->next = cur->next;
		    cur->next = new_node;
		    cur = cur->next->next;
		}
		cur = head;
		while(cur)
		{
		    cur->next->random = cur->random ? cur->random->next : 0;//cur->random->next;
		    cur = cur->next->next;
		}
		cur = head;
		RandomListNode new_list(-1);
		new_node = &new_list;
		while(cur)
		{
		    new_node->next = cur->next;
		    cur->next = cur->next->next;
		    cur = cur->next;
		    new_node = new_node->next;
		}
		return new_list.next;
	    }
		        
};
RandomListNode * make()
{
    RandomListNode head(-1); 
    for(int i=1; i>=0; i--)
    {
	RandomListNode *new_node = new RandomListNode(i);
	new_node->next = head.next;
	head.next = new_node;
    }
    RandomListNode *st = head.next->next;
    while(st && st->next)
    {
	st->next->random = st;
	st = st->next;
    }
    return head.next;
}
void print_list(RandomListNode *list)
{
    RandomListNode *cur = list;
    while(cur)
    {
	if(cur->random)
	    cout<<cur->label<<"->"<<cur->random->label<<endl;
	else
	    cout<<cur->label<<"->null"<<endl;
	cur = cur->next;
    }
}
int main()
{
    RandomListNode *head = make();
    print_list(head);
    Solution so;
    RandomListNode *new_list = so.copyRandomList(head);
    print_list(new_list);
    return 0;
}
