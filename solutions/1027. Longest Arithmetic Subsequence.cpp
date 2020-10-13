class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int n=arr.size();
        if(n==2)
            return 2;
        int dp[n][2500];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int diff=arr[i]-arr[j];
                if(dp[j][1500+diff]!=0)
                    dp[i][1500+diff]=max(dp[i][diff+1500],dp[j][diff+1500]+1);
                else
                    dp[i][1500+diff]=max(2,dp[i][1500+diff]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2500;j++)
                ans=max(ans,dp[i][j]);
        }
        return ans;
        
    }
};
