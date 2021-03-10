class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.length(),m=t.length();
        if(n==0)
            return m;
        if(m==0)
            return n;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n+1;i++)
            dp[i][m]=n-i;
        for(int i=0;i<m+1;i++)
            dp[n][i]=m-i;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
            }
        }
        return dp[0][0];
            
    }
};
