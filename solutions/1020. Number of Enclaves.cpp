class Solution {
public:
    int vis[600][600];
    int n,m;
    void func(int i,int j,vector<vector<int>>&arr){
        
        if(i==-1||j==-1||i==n||j==m)
            return ;
        // cout<<i<<" "<<j<<" "<<endl;
        if(vis[i][j]==1)
            return ;
        
        if(arr[i][j]==0)
            return ;
        // cout<<"pop";
        vis[i][j]=1;
        func(i+1,j,arr);
        func(i,j+1,arr);
        func(i,j-1,arr);
        func(i-1,j,arr);
    }
    int numEnclaves(vector<vector<int>>&arr) {        
        n=arr.size();
