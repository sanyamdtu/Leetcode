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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int n=0,m=0;
        ListNode *t=a;
        while(t){
            n++;
            t=t->next;
        }
        t=b;
        while(t){
            m++;
            t=t->next;
        }
        // cout<<n<<m;
        if(m>n){
          swap(n,m);
          swap(a,b);
        }
        while(n-m>0){
            n--;
            a=a->next;
        }
        while(a&&a!=b)
        {
            a=a->next;
            b=b->next;
        }
        return a;
    }
};
