int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
int dp[300][300];
class Solution {
public:
    int n,m;
    int func(int i,int j,vector<vector<int>>& arr){
        if(dp[i][j]>0)
            return dp[i][j];
        int a=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&y>=0&&x<n&&y<m){
                if(arr[x][y]>arr[i][j])
                    a=max(1+func(x,y,arr),a);
            }    
        }
        return dp[i][j]=a;        
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
        n=arr.size();
        m=arr[0].size();
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(func(i,j,arr),ans);
            }
        }
        return ans;
    }
};
