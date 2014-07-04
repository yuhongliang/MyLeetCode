#include <iostream>
using namespace std;

/*******Definition for singly-linked list.*/
  struct ListNode {                          
      int val;                               
      ListNode *next;                        
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 /*******submission code*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head) return ;
        
        ListNode *mid = findmidle(head);
        ListNode *L2 = mid->next;
        mid->next = NULL;
        L2 = reverselist(L2);
        //return mergelist(head,L2);
        ListNode ln(-1);
		ListNode *cur = &ln;
		while(head && L2){
			cur->next = head;
			head = head->next;
			cur = cur->next;
			cur->next = L2;
			L2 = L2->next;
			cur = cur->next;
		}
		if(head || L2){
			cur->next = head ? head : L2;
		}
    }
private:
	ListNode *findmidle(ListNode *head){
		if(!head || !head->next) return head;
		
		ListNode *slow = head;
		ListNode *fast = head->next;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode *reverselist(ListNode *head){
		if(!head)return head;
		ListNode *pre = head;
		ListNode *cur = head->next;
		ListNode *next = NULL;
		head->next = NULL;
		while(cur){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};


/******for test*/
ListNode *makelist(){
	int testcase[] = {1,2};
	ListNode *list = NULL;
	ListNode *cur = NULL;
	for(int index = 0; index < sizeof(testcase)/sizeof(int); index++){
		if(!list){
			list = new ListNode(testcase[index]);
			cur = list;
		}
		else{
			cur->next = new ListNode(testcase[index]);
			cur = cur->next;
		}
	}
	return list;
}

void printList(ListNode *list){
	if(!list){
		cout<<"NULL"<<endl;
	}
	else{
		ListNode *cur = list;
		while(cur){
			cout<<cur->val<<"-";
			cur = cur->next;
		}
		cout<<"NULL"<<endl;
	}
}
int main()
{
	ListNode *list = 0;
	list = makelist();
	printList(list);
	Solution so;
	so.reorderList(list);
	printList(list);
	return 0;
}
