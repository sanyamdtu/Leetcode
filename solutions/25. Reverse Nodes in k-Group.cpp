                t->next=temp;
            }
            temp=t;
            c++;
            if(k==c){
                if(ans_t){
                    ans_t->next=temp;
                }
                else{
                    ans=temp,ans_t=temp;
                }
                while(ans_t->next){
                    ans_t=ans_t->next;
                }
                c=0;
                temp=NULL;
            }
            h=h->next;
            
        }
        ListNode* p = NULL;
        while(temp){
             ListNode *t=new ListNode(temp->val);
            if(p){
                t->next=p;
            }
            p=t;
             temp=temp->next;
        }
        if(ans_t)
        ans_t->next=p;
        return ans;
    }
};
