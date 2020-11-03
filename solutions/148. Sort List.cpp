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
    ListNode *merge(ListNode * a, ListNode *b){
    if(!a)
        return b;
    if(!b)
        return a;
    ListNode *t=new  ListNode();
​
    if(a->val>b->val){
        t->val=b->val;
        b=b->next;
        t->next=merge(a,b);
    }
    else{
        t->val=a->val;
        a=a->next;
        t->next=merge(a,b);
    }
    return t;
}
    ListNode*  msort(ListNode *head){
    if(head==NULL||head->next==NULL)
        return head ;
    ListNode *f,*sl;
    f=sl=head;
    ListNode *temp=NULL;
    while(f&&f->next){
        temp=sl;
        sl=sl->next;
        f=f->next->next;
    }
    temp->next=NULL;
    ListNode *l=msort(head);
    ListNode *r=msort(sl);
    ListNode *s=merge(l,r);
    return s;
}
    ListNode* sortList(ListNode* head) {
        return msort(head);
    }
};
