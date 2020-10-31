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
    int numComponents(ListNode* head, vector<int>& arr) {
        int c=0,f=0;
        map<int,bool> m;
        for(auto i:arr)
            m[i]=true;
        while(head){
            if(m[head->val]){
                if(f==0){
                    c++;
                    f=1;
                }
            }
            else
            {
                f=0;
