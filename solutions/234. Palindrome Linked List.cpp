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
    bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=slow;
        ListNode* b=NULL;
        while(a){
            ListNode* t=new ListNode(a->val);
            t->next=b; 
            b=t;
            a=a->next;
        }
        int f=0;
        while(b&&head!=slow){
            if(head->val!=b->val){
                f=1;
                break;
            }
            b=b->next;
            head=head->next;
        }
        return f==0;
    }
};
