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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* node=head;
        for(int i=0;i<k;i++)
        {
            if(!node) return head;
            node=node->next;
        }
         ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextnode=head;
        ListNode* temp=head;
        int c=0,total=0;
        while(temp!=NULL){
            temp=temp->next;
            total++;
        }
        while(curr!=NULL && c<k)
         {
            nextnode=nextnode->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            c++;
         }
         head->next=reverseKGroup(curr,k);
         return prev;
    }
};