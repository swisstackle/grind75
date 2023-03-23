#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head){	
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
int main(){
	struct ListNode one, two, three;
	one.next = &two; two.next = &three; three.next = NULL;
	one.val = 1; two.val = 2; three.val = 3;
	printf("%d\n", middleNode(&one)->val);
}
