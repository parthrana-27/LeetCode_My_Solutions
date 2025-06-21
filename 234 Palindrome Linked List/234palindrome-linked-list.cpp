/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next == NULL) return head;
        ListNode* new_h=reverse(head->next);
        ListNode* front =head->next;
        front->next=head;
        head->next=NULL;
        return new_h;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next !=NULL && fast->next->next !=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* new_h=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=new_h;
        while(second!=NULL){
            if(first->val != second->val){
                reverse(new_h);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(new_h);
        return true;
    }
};