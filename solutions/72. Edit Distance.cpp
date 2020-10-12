class Solution {
public:
    int minDistance(string a, string b) {
        int n=a.length(),m=b.length();
        if(m==0&&n==0)
            return 0;
        if(m==0)
            return n;
        if(n==0)
            return m;
        int dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=1+dp[i-1][0];
        for(int i=1;i<=m;i++)
            dp[0][i]=1+dp[0][i-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[n][m];
    }
};
