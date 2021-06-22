class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[0][0]=0;
        for(int i=0;i<k+1;i++)
            dp[i][0]=0;
        for(int i=1;i<k+1;i++){
            int maxi=dp[i-1][0]-arr[0];
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1];
                dp[i][j]=max(dp[i][j],maxi+arr[j]);
                maxi=max(dp[i-1][j]-arr[j],maxi);
            }
        }
        return dp[k][n-1];
        
    }
};
