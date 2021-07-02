/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *curr=head->next,*prev=head,*fwd=NULL;
        prev->next=NULL;
        while(curr){
            fwd=curr->next;
            curr->next=NULL;
            if(prev->val!=curr->val){
                prev->next=curr;
                prev=curr;
            }
            curr=fwd;
        }
        return head;
    }
};
