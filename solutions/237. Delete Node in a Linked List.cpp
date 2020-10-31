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
    void deleteNode(ListNode* &h) {
      // ListNode*  temp=h;
        h->val=h->next->val;
        h->next=h->next->next;
    }
};
