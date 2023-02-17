/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 #include <stdio.h>
 #include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 != NULL) {
        return list2;
    }
    if(list2 == NULL && list1 != NULL) {
        return list1;
    }
    if(list1 == NULL && list2 == NULL) {
        return NULL;
    }
    struct ListNode* final;
    // Find last node of list2
    struct ListNode* lastNodeList2;
    lastNodeList2 = list2;
    struct ListNode* lastNodeList1;
    lastNodeList1 = list1;

    int list1Length = 1;
    int list2Length = 1;
    while (lastNodeList2->next != NULL) {
        lastNodeList2 = lastNodeList2->next;
        list2Length++;
    }
    while (lastNodeList1->next != NULL) {
        lastNodeList1 = lastNodeList1->next;
        list1Length++;
    }

    if(list1->val > list2->val) {
        final = list2;
        list2 = list2->next;
        list2Length--;            
    } else {
        final = list1;
        list1 = list1->next;
        list1Length--;  
    }
    struct ListNode* origin = final; // should never change
    while(list1Length > 0 && list2Length > 0) {
        if(list1->val > list2->val) {
            final->next = list2;
            final = final->next;
            list2 = list2->next;
            list2Length--;            
        } else {
            final->next = list1;
            final = final->next;
            list1 = list1->next;
            list1Length--;  
        }
    }

    while (list1Length > 0) {
        final->next = list1;
        final = final->next;
        list1 = list1->next;
        list1Length--; 
    }
    while (list2Length > 0) {
        final->next = list2;
        final = final->next;
        list2 = list2->next;
        list2Length--; 
    }
    return origin;
}

int main(int argc, char *argv[]) {
    struct ListNode n1, n1_2, n1_3, n1_4, n2, n2_2, n2_3, n2_4;

    n1.val = 1;
    n1_2.val = 2;
    n1_3.val = 4;
    n1_4.val = 5;

    n2.val = 3;
    n2_2.val = 6;
    n2_3.val = 7;
    n2_4.val = 9;
    
    n1.next = &n1_2;
    n1_2.next = &n1_3;
    n1_3.next = &n1_4;

    n2.next = &n2_2;
    n2_2.next = &n2_3;
    n2_3.next = &n2_4;

    n2_4.next = NULL;
    n1_4.next = NULL;

    mergeTwoLists(&n1, &n2);
    printf("%p", &n2);
}
