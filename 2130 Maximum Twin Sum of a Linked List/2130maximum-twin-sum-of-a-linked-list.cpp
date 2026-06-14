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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* sec=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* cur=sec;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode* s_head=prev;
        ListNode* first=head;
        int ma=0;
        while(first!=nullptr && s_head!=nullptr){
            int sum=first->val+s_head->val;
            ma=max(ma,sum);
            first=first->next;
            s_head=s_head->next;
        }
        return ma;
    }
};