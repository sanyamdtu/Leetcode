class Solution {
public:
    int n;
    int d;
    int dp[2000];
    int func(int s,vector<vector<int>>arr){
        if(s==n)
            return 0;
        // cout<<"pop";
        if(dp[s]!=-1)
            return dp[s];
        int curr=0,ans=INT_MAX,h=INT_MIN;
        for(int i=s;i<n;i++){
            curr+=arr[i][0];
            h=max(h,arr[i][1]);
            if(curr<=d)
                ans=min(ans,h+func(i+1,arr));
        }
        return dp[s]=ans;
    }
    int minHeightShelves(vector<vector<int>>& arr, int shelf_width) {
        n=arr.size();
        d=shelf_width;
        if(n==0)
            return 0;
        memset(dp,-1,sizeof(dp));
        return func(0,arr);
        
    }
};
