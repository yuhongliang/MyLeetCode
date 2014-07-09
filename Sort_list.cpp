#include <iostream>
using namespace std;
/******Definition for singly-linked list.*/
 struct ListNode {                          
     int val;                               
     ListNode *next;                        
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 
/******code to be submission*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	return msort(head);
    }
private:
    ListNode *msort(ListNode *head){
    	if(!head || !head->next){
    		return head;
    	}
    	ListNode *fast = head;
    	ListNode *slow = head;
    	while(fast->next && fast->next->next){
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	fast = slow->next;
    	slow->next = NULL;
    	ListNode *L1 = msort(head);
    	ListNode *L2 = msort(fast);	
    	return mergeList(L1,L2);
    }
    ListNode *mergeList(ListNode *L1,ListNode *L2){
    	ListNode L(-1);
    	ListNode *p_list = &L;
		if(!L1 || !L2){
    		return L1 ? L1 : L2;
    	}
    	while(L1 && L2){
    		if(L1->val <= L2->val){
    			p_list->next = L1;
    			L1 = L1->next;
    		}
    		else{
    			p_list->next = L2;
    			L2 = L2->next;
    		}
    		p_list = p_list->next;
    	}
    	p_list->next = L1 ? L1 : L2;
    	return L.next;
    }

};
/******end code to be submission*/


/******for test*/
ListNode *makelist(){
	int testcase[] = {3,1};
	ListNode *list = NULL;
	ListNode *cur = NULL;
	for(size_t index = 0; index < sizeof(testcase)/sizeof(int); index++){
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
	list = so.sortList(list);
	printList(list);
	return 0;
}
