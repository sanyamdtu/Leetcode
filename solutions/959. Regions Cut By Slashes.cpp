        for(int i=0;i<10000;i++)
            p[i]=i;
        int ans=1;
        for(int i=0;i<n;i++){
            int x=i*(n+1);
            int y=(i+1)*(n+1);
            un(x,y,p,r);
            un(x+n,y+n,p,r);
        }
        for(int i=0;i<n;i++){
            int x=i;
            int y=i+1;
            un(x,y,p,r);
            un(x+(n)*(n+1),y+(n)*(n+1),p,r);
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].length();j++){
                if(arr[i][j]=='\\'){
                    int x=(i)*(n+1)+j;
                    int y=(i+1)*(n+1)+j+1;
                    if(find(x,p)==find(y,p)){
                        ans++;
                        cout<<x<<" "<<y<<endl;
                    }
                        
                    else
                        un(x,y,p,r);
                }
                else if(arr[i][j]=='/'){
                    int x=(i)*(n+1)+j+1;
                    int y=((i+1)*(n+1))+j;
                    cout<<i<<" "<<j<<" "<<x<<" "<<((n+1))<<endl;
                    if(find(x,p)==find(y,p))
                        ans++;
                    else
                        un(x,y,p,r);
                }
                
            }
        }
        return ans;
        
    }
};
