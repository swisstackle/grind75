#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head){
	if(head == NULL) {
		return NULL;
	}
	if(head->next == NULL) {
		return head;
	}
	if(head->next->next == NULL) {
		head->next->next = head;
		head->next = NULL;
		return head->next;
	}
	struct ListNode *current = head->next;
	struct ListNode *last = head;
	struct ListNode *third = head->next->next;
	while(current != NULL) {
		if(current->next != NULL) {
			third = current->next;
		} else {
			third = NULL;
		}
		current->next = last;
		last = current;
		current = third;	
	}
	return last;
}
int main() {
	struct ListNode head, second, third, fourth, fifth;
	head.val = 1;
	second.val = 2;
	third.val = 3;
	fourth.val = 4;
	fifth.val = 5;
	head.next = &second;
	second.next = &third;
	third.next = &fourth;
	fourth.next = &fifth;
	fifth.next = NULL;
	struct ListNode *reversed = reverseList(&head);
	printf("%d %d %d %d %d\n", reversed->val, reversed->next->val, reversed->next->next->val, reversed->next->next->next->val, reversed->next->next->next->next->val, reversed->next->next->next->next->next->val);
}
