        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i = 2; i <=m; i++) 
            if (p[i-1] == '*' && (dp[0][i-2]==1||dp[0][i-1]))
               dp[0][i] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(dp[i][j-2]+dp[i][j-1]>0)
                        dp[i][j]=1;
                    else if(p[j-2]==s[i-1]||p[j-2]=='.')
                        dp[i][j]=dp[i-1][j];
                }
                else{
                    if(p[j-1]==s[i-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
            }
        }
       
        return (dp[n][m]==1);
    }
};
