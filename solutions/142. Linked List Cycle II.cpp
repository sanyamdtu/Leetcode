/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode * s,*f;
        s=f=head;
        int c=0;
        while(f&&f->next&&(s!=f||c==0)){
            c++;
            s=s->next;
            f=f->next->next;
        }
        if(s!=f)
            return NULL;
        // cout<<c;
        s=head;
        // cout<<s->val<<" "<<f->val;
        while(s!=f){
            s=s->next;
            f=f->next;
            c++;
        }
        return s;
    }
};
