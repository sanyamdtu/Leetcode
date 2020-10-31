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
    vector<int> nextLargerNodes(ListNode* head) {
        // vector<int> v;
        ListNode* temp=NULL ;
        while(head){
            ListNode* node=new ListNode(head->val);
            node->next=temp;
            temp=node;
            head=head->next;
        }
        stack<int> s;
        vector<int> v;
        while(temp){
            if(s.empty()){
                s.push(temp->val);
                v.push_back(0);
            }
            else{
                while(!s.empty()&&s.top()<=temp->val){
                    s.pop();
                }
                
                int c=0;
                if(!s.empty())
                    c=s.top();
                v.push_back(c);
                s.push(temp->val);
            }
            temp=temp->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
