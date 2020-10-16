class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        if(n<=1)
            return n;
        map<int,int> m;
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            int x=m[arr[i]+d]; 
            int c=-1;
            if(x!=0)
                c=dp[x-1];
            if(c!=-1){
                dp[i]=1+c;
            }
            m[arr[i]]=i+1;
        }
        int x=0;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<" ";
            x=max(x,dp[i]);
        }
            
        return x;
    }
};
