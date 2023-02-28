#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head == NULL) {
        return false;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
		if(slow != NULL && fast != NULL) {
			if(slow == fast) {
				return true;
			}
		}
    }
    return false;
}

int main() {
	struct ListNode head;
	struct ListNode two;
	struct ListNode zero;
	struct ListNode four;

	head.val = 3;
	two.val = 2;
	zero.val = 0;
	four.val = 4;

	head.next = &two;
	two.next = &zero;
	zero.next = &four;
	four.next = &two;
	
	printf("%d", hasCycle(&head));
}
