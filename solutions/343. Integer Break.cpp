class Solution {
public:
    int dp[100][100];
    int func(int n,int c=0){
        if(n==0)
            return (c>=2);
        if(dp[n][c]!=-1)
            return dp[n][c];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(i*func(n-i,c+1),ans);
        }
        return dp[n][c] =ans;
    }
    int integerBreak(int n) {
        // if(n==2)
        //     return 1;
        memset(dp,-1,sizeof(dp));
        return func(n);
    }
};
