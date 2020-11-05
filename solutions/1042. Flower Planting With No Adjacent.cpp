class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& arr) {
        vector<vector<int>> g(n+1);
        for(int i=0;i<arr.size();i++){
            g[arr[i][0]].push_back(arr[i][1]);
            g[arr[i][1]].push_back(arr[i][0]);
        }
        int vis[n+1];
        memset(vis,-1,sizeof(vis));
        queue<int> q;
        for(int gr=1;gr<=n;gr++){
            if(vis[gr]==-1)
                q.push(gr);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int s=1;s<=4;s++){
                    int f=1;
                    for(auto i:g[a]){
                        if(s==vis[i])
                            f=0;
                    }
                    if(f==1){
                        vis[a]=s;
                        break;
                    }
                }
            }
        }
        vector<int> v;
        for(int i=1;i<=n;i++)
                v.push_back(vis[i]);
        return v;
    }
};
