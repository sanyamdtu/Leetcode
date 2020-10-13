class Solution {
public:
    int dp[100];
    int func(int n){
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(i*func(n-i),ans);
        }
        return dp[n] =ans;
    }
    int integerBreak(int n) {
        // if(n==2)
        //     return 1;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<n;i++)
            ans=max(i*func(n-i),ans);
        return ans;
    }
};
