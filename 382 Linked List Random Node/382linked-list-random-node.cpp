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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head=head;
    }
    
    int getRandom() {
        ListNode* cur=head;
        int res=cur->val;
        int i=1;
        cur=cur->next;
        while(cur!=nullptr){
            if(rand()%(i+1)==0){
                res=cur->val;
            }
            cur=cur->next;
            i++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */