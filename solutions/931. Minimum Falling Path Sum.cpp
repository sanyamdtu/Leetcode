class Solution {
public:
    int func(int arr[][100],int i,int j,int dp[][100],int n){
        if(i==n)
            return 0;
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        int a=func(arr,i+1,j,dp,n);
        if(j!=0)
            a=min(func(arr,i+1,j-1,dp,n),a);
        if(j!=n-1)
            a=min(func(arr,i+1,j+1,dp,n),a);
        return dp[i][j]=a+arr[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& A) {
     
        int n=A.size();
        int arr[n][100];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                arr[i][j]=A[i][j];
            }
        }
        int ans=INT_MAX;
        int dp[n][100];
        for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dp[i][j]=INT_MAX;
        }
    }
        for (int i = 0; i < n; ++i)
        {
           ans=min(ans,func(arr,0,i,dp,n));
        }
        return ans;
    }
};
