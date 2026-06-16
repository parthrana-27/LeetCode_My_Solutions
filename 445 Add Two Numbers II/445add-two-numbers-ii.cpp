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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int c=0;
        ListNode* head=nullptr;
        while(!s1.empty() || !s2.empty() || c){
            int v1=s1.empty()?0:s1.top();
            int v2=s2.empty()?0:s2.top();
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            int s=v1+v2+c;
            c=s/10;
            ListNode* node=new ListNode(s%10);
            node->next=head;
            head=node;
        }
        return head;
    }
};