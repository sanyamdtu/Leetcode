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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)
            return head;
        ListNode* temp=head;
        ListNode* odd=new ListNode(head->next->val);
        ListNode* h=odd;
        temp->next=head->next->next;
        temp=temp->next;
        while(temp&&temp->next){
            odd->next=new ListNode(temp->next->val);
            odd=odd->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        temp=head;
        while(temp&&temp->next){
            temp=temp->next;
        }
        temp->next=h;
        return head;
    }
};
