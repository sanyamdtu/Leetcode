class Solution {
public:
    
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return 0;
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        dp[0][1]=-arr[0];
        dp[1][1]=max(-arr[1],dp[0][1]);
        dp[1][0]=max(dp[0][1]+arr[1],0);
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+arr[i]);
            dp[i][1]=max(dp[i-1][1],(dp[i-2][0]-arr[i]));
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        for(int i=0;i<n;i++){
            cout<<dp[i][0]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<dp[i][1]<<" ";
        }
        
            
        return ans;
    }
};
