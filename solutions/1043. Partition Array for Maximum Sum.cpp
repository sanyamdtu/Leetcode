class Solution {
public:
    int func(int id,vector<int> arr,int k,int n){
        if(id==n)
            return 0;
        int ans=-1000000000;
        int curr=-1000000;
        for(int i=id;i<n&&i<id+k;i++){
            curr=max(curr,arr[i]);
            ans=max(ans,curr*(i-id+1)+func(i+1,arr,k,n));
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       // return func(0,arr,k,arr.size());
        int n=arr.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            int ans=-1;
            int curr=-1;
            for(int j=i;j<n&&j<i+k;j++){
                curr=max(curr,arr[j]);
                ans=max(ans,curr*(j-i+1)+dp[j+1]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
