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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v(k,NULL);
        ListNode* temp=head;
        int n=0,d=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        int c=0;
        if(n<=k){
            c=1;
        }
        else{
            c=(n/k);
            d=(n%k);
        }
        int i=0,ans=0;
        ListNode* h=NULL,*t=NULL;
        while(temp){
            cout<<temp->val<<" ";
            if(h==NULL){
                ans=0;
                h= new ListNode(temp->val);                
                t=h;
                ans++;
                 temp=temp->next;
            }
            else{
                if(ans==c){
                    if(d){
                        h->next=new ListNode(temp->val);
                        temp=temp->next;
                        d--;
                    }
                    v[i]=t;
                    h=NULL;
