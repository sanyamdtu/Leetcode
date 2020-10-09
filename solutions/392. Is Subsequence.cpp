class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m==0&&n==0)
            return true;
        if(n>m)
            return false;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n][m];
        return dp[n][m]==min(t.length(),s.length());
    }
};
