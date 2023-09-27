/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseLinkedList(struct ListNode* root) {
    struct ListNode* ans = NULL;

    while(root != NULL) {
       struct ListNode* temp = root->next;
           root->next = ans;
           ans = root;
           root = temp;       
    }

    return ans;
    }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* a = reverseLinkedList(l1);
    struct ListNode* b = reverseLinkedList(l2);
    struct ListNode* ans = NULL;
    int totalSum = 0;
    
    while(a != NULL || b != NULL || totalSum > 0) {

        if(a != NULL) {
            totalSum += a->val;

            a = a->next;
        }
        if(b != NULL) {
            totalSum += b->val;
            b = b->next;
        }
        
        struct ListNode* temp =   malloc(sizeof(struct ListNode));
        temp->val = (totalSum%10);
        totalSum = totalSum/10;
        temp->next = ans;
        ans = temp;

    }
    return ans;
} 
