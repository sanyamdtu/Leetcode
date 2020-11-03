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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return ;
        ListNode *s,*f;
        s=f=head;
        ListNode* temp=NULL;
        while(f&&f->next){
            temp=s;
            s=s->next;
            f=f->next->next;
        }
        ListNode* h=head;
        temp->next=NULL;
        ListNode* r=s;
        s=NULL;
        while(r){
            ListNode* t=new ListNode(r->val);
            if(s){
