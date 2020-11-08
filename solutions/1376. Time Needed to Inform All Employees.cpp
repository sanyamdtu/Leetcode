class Solution {
public:
    int vis[200000];
    int func(int src,vector<vector<int>> &g,vector<int>& arr){
        int c=0;
        for(auto i:g[src]){
            if(vis[i]==0){
                vis[i]=1;
                c=max(c,func(i,g,arr));
            }
        }
        return c+arr[src];
    }
    int numOfMinutes(int n, int headID, vector<int>& p, vector<int>& arr) {
        memset(vis,0,sizeof(vis));
        vector<vector<int>> g(n);
        for(int i=0;i<p.size();i++){
            if(p[i]!=-1)
            g[p[i]].push_back(i);
            if(p[i]!=-1)
            g[i].push_back(p[i]);
        }
        vis[headID]=1;
        return func(headID,g,arr);
        return 0;
    }
};
