/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur=head;
        while(cur){
            if(cur->child){
                Node* cur_next=cur->next;
                Node* cur_child=cur->child;
                flatten(cur_child);

                Node* child_tail=cur_child;
                while(child_tail->next){
                    child_tail=child_tail->next;
                }
                cur->next=cur_child;
                cur_child->prev=cur;
                cur->child=nullptr;
                if(cur_next){
                    child_tail->next=cur_next;
                    cur_next->prev=child_tail;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};