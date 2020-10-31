            while(a&&b){
                if(a->val>b->val){
                    ListNode* t=new ListNode(b->val);
                    if(!temp){
                        temp=t;
                        f=t;
                    }
                    else
                    {
                        f->next=t;
                        f=t;
                    }
                    b=b->next;
                }
                else{
                    ListNode* t=new ListNode(a->val);
                    a=a->next;
                    if(!temp){
                        temp=t;
                        f=t;
                    }
                    else
                    {
                        f->next=t;
                        f=t;
                    }
                }
            }
            if(a){
                f->next=a;
            }
            if(b){
                f->next=b;
            }
            return temp;
        }
        
        
    }
};
