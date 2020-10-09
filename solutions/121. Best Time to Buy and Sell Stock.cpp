class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int n=prices.size();
        if(n==0)
            return 0;
        int dp[n];
        dp[0]=0;
        int f=prices[0];
          for(int i=1;i<n;i++){
              dp[i]=prices[i]-f;
              f=min(prices[i],f);
          }
    
        for(int i=1;i<n;i++){
            p=max(p,dp[i]);
        }
        return p;
    }
};
