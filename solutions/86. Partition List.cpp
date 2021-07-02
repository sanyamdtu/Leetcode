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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a=new ListNode(-1);
        ListNode *b=new ListNode(-1);
        ListNode *p=a,*q=b;
        while(head){
            ListNode *fwd=head->next;
            head->next=NULL;
            if(head->val>=x){
                q->next=head;
                q=head;
            }
            else{
                p->next=head;
                p=head;
            }                
