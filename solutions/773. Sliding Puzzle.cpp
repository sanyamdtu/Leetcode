        g[2].push_back(5);
        g[3].push_back(0);
        g[3].push_back(4);
        g[4].push_back(1);
        g[4].push_back(3);
        g[4].push_back(5);
        g[5].push_back(2);
        g[5].push_back(4);
        string y="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                y+='0'+arr[i][j];
            }
        }
        queue<string> q;
        unordered_map<string,int> dist,vis;
        q.push(x);
        dist[x]=0;
        while(!q.empty()){
            auto a=q.front();
            // cout<<a<<endl;
            if(a==y)
                return dist[a];
            q.pop();
            for(int i=0;i<a.length();i++){
                if(a[i]=='0'){
                    // cout<<"pop"l
                    for(auto j:g[i]){
                        string k=a;
                        swap(k[i],k[j]);
                        if(!vis[k]){
                            vis[k]=true;
                            q.push(k);
                            dist[k]=dist[a]+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
