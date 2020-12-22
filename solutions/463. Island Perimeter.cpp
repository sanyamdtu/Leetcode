class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& arr,int n,int m){
        // cout<<i<<" "<<j<<endl;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        int ans=0;
        arr[i][j]=-1;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            // cout<<x<<" "<<y<<endl;
            if(x<0||y<0||x>=n||y>=m){
                ans++;
            }
            else{
                if(arr[x][y]==1){
                    
                    ans+=bfs(x,y,arr,n,m);
                }
                else if(arr[x][y]==0)
                    ans++;
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    return bfs(i,j,arr,n,m);
                }
            }
        }
        return 0;
    }
};
