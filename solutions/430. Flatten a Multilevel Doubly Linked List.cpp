/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
​
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> q;
        if(head)
            q.push(head);
        
        Node* temp=NULL;
        Node* h=temp;
        while(!q.empty()){
            Node* a=q.top();
            q.pop();
             Node *t=new Node (a->val);
            if(temp==NULL){
               
                temp=t;
                h=t;
            }            
            else
            {
                temp->next=t;
                t->prev=temp;
                temp=temp->next;
            }
            
            if(a->next)
                q.push(a->next);
            if(a->child)
                q.push(a->child);
        }
        return h;
    }
};
