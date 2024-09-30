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
    int numComponents(ListNode* head, vector<int>& nums) {
        std::unordered_set<int>nums_set(nums.begin(),nums.end());
        struct ListNode *temp=head;
        int count=0;
        bool comp=false;
        while(temp !=NULL)
        {
           if(nums_set.count(temp->val))
           {
            if(!comp)
            {
                count++;
                comp=true;
            }
           }else{
            comp=false;
           }
           temp=temp->next;

        }
        return count;
    }
};