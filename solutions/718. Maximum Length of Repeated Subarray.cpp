class Solution {
public:
    int n,m;
    int findLength(vector<int>& a, vector<int>& b) {
        n=a.size();
        m=b.size();
        if(n==0||m==0)
            return 0;
       int dp[n][m];
        for(int i=0;i<n;i++)
            if(a[i]==b[0])
                dp[i][0]=1;
            
            else
                dp[i][0]=0;
        for(int i=0;i<m;i++)
            if(b[i]==a[0])
                dp[0][i]=1;
            
            else
                dp[0][i]=0;
         for(int i=1;i<n;i++){
             for(int j=1;j<m;j++){
                 if(a[i]==b[j])
                     dp[i][j]=dp[i-1][j-1]+1;
                 else
                     dp[i][j]=0;
             }
         } 
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ans=max(ans,dp[i][j]);
        }
        return ans;
        
    }
};
