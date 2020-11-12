class Solution {
public:
    int n;
    int vis[4000] ;
    bool func(vector<vector<int>>& arr,int i){
        bool ans=true;
        for(auto a:arr[i]){
            if(vis[a]==-1){
                vis[a]=1-vis[i];
                ans=ans&(func(arr,a));
            }
            else{
                ans=ans&(vis[a]==1-vis[i]);
            }
        }
        return ans;
    }
    bool possibleBipartition(int N, vector<vector<int>>& g) {
        n=N;
        vector<vector<int>> arr(n+1);
        for(auto i:g){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        memset(vis,-1,sizeof(vis));
        bool ans=true;
        for(int i=1;i<n+1;i++){
            if(vis[i]==-1){
                vis[i]=0;
                ans=ans&func(arr,i);
            }
        }
        return ans;
    }
};
