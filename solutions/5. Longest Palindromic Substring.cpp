class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        if(n<=1)
            return s;
        int dp[n][n];
        int ans=1,idx=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)
                    dp[i][j]=1;
                else {
                    if(s[i]==s[j]){
                        if(i+1==j)
                            dp[i][j]=2;
                        else if(dp[i+1][j-1]!=0)
                            dp[i][j]=dp[i+1][j-1]+2;
                        else
                            dp[i][j]=0;
                    }
                    else
                        dp[i][j]=0;
                }
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ans==dp[i][j]){
                    for(int k=i;k<=j;k++)
                        res+=s[k];
                    return res;
                }
            }
            
        }
        return "";
        
    }
};
