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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=head->next;
        ListNode* prev=head;
        while(cur){
            if(prev->val<=cur->val){
                prev=cur;
                cur=cur->next;
                continue;
            }
            ListNode* s=dummy;
            while(s->next->val < cur->val){
                s=s->next;
            }
            prev->next=cur->next;
            cur->next=s->next;
            s->next=cur;
            cur=prev->next;
        }
        return dummy->next;
    }
};