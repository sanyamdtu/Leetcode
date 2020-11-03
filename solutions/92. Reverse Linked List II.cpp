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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int l=0;
        ListNode* h=head;
        ListNode* temp=NULL;
        if(h==NULL||h->next==NULL)
            return head;
        while(h){
            l++;
            if(l>=m&&l<=n){
                ListNode* t=new ListNode(h->val);
                if(temp==NULL)
                    temp=t;
                else{
                    t->next=temp;
                    temp=t;
                }
            }
            h=h->next;
           
        }
        h=head;
        l=0;
        while(h){
            l++;
            if(l>=m&&l<=n){
                h->val=temp->val;
                temp=temp->next;
            }
            h=h->next;
        }
        return head;
    }
};
​
