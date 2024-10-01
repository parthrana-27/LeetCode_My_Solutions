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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }
        ListNode* prev=NULL;
        ListNode* current=head;
        while(current != NULL)
        {
        if (current->val == val)
        {
            prev->next=current->next;
        }else{
            prev=current;
        }   
         current=current->next;

        }
        return head;
    }
};

// 1 2 3 7 8