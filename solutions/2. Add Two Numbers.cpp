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
    ListNode * reverse(ListNode *head){
        ListNode *prev=NULL,*curr=head,*fwd=NULL;
        while(curr){
            fwd=curr->next;
            curr->next=NULL;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    ListNode *addTwoNumbers(ListNode *a, ListNode *b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        // a=reverse(a);
