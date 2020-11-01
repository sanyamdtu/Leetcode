                temp=t;
            }
            else{
                t->next=temp;
                temp=t;
            }
        }
        while(!p.empty()){
            c=p.top()->val+c;
            ListNode* t=new ListNode(c%10);
            c/=10;
            if(temp==NULL){
                temp=t;
            }
            else{
                t->next=temp;
                temp=t;
            }
            p.pop();
        }
        while(!q.empty()){
            c=q.top()->val+c;
            ListNode* t=new ListNode(c%10);
            c=c/10;
            if(temp==NULL){
                temp=t;
            }
            else{
                t->next=temp;
                temp=t;
            } 
            q.pop();
        }
        if(c%10!=0){
            ListNode* t=new ListNode(c%10);
            if(temp==NULL){
                temp=t;
            }
            else{
                t->next=temp;
                temp=t;
            } 
        }
        return temp;
    }
};
