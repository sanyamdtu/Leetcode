class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int m=arr[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++)
            dp[i][0]=arr[i][0];
        for(int i=0;i<m;i++)
            dp[0][i]=arr[0][i];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]==0)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans+=dp[i][j];
        return ans;
    }
};
