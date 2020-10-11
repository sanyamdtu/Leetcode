class Solution {
public:
    int countSubstrings(string s) {
        long long dp[1003][1004];
​
        int n=s.length();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][i]=1;
        for(int i=n;i>=1;i--){
            for(int j=n;j>=i+1;j--){
                if(s[i-1]==s[j-1])
                {
                    if(i+1>=j-1)
                        dp[i][j]+=1;
                    else
                         dp[i][j]+=dp[i+1][j-1];
                    
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans+=dp[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
                
        }
        return ans;
        // return 0;
    }
};
