class Solution {
public:
    double knightProbability(int n, int k, int a, int b) {
        double dp[n][n][k+1];
        memset(dp,0,sizeof(dp));
        dp[a][b][k]=1;
         int dx[]={ 2, 1, -1, -2, -2, -1, 1, 2 }; 
        int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        while(k>0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int l=0;l<8;l++){
                        int x=i+dx[l];
                        int y=j+dy[l];
                        if(x>=0&&y>=0&&x<n&&y<n){
                            dp[x][y][k-1]+=double(dp[i][j][k]*(0.125));
                            // cout<<dp[x][y][k-1]<<endl;
                        }
                    }
                }
            }
            k--;
        }
        double ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans+=dp[i][j][0];
        return ans;
            
    }
};
