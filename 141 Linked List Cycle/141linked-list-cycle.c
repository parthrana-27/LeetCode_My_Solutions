/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL){
        return false;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    do{
        if(fast==NULL || fast->next==NULL){
            return false;
        }
        slow= slow->next;
        fast=fast->next->next;
    }
    while(!(fast==slow));
    return true;
}