class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        int dp[n][2];
        dp[0][0]=0;
        dp[0][1]=arr[0];
        dp[1][0]=arr[0];
        dp[1][1]=arr[1];
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+arr[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
