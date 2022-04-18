class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        bool dp[200][200];  //   n and m
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        dp[0][1]=(p[0]=='*'||(m>=2&&p[1]=='*'));
        for(int i=2;i<=m;i++){
            if(p[i-1]=='*'){
                dp[0][i]=dp[0][i-2];
            }
            else
                dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    if(p[j-1]=='*'){
                       dp[i][j]=dp[i][j-2];
                       dp[i][j]=(dp[i][j] || dp[i][j-1]); 
                        if(s[i-1]==p[j-2] || p[j-2]=='.' )
                        {
                            dp[i][j]=(dp[i][j] || dp[i-1][j]);
                        }
                    }
                }
            }
        }
        return dp[n][m];
    }
};
