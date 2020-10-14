class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int m=10001;
        int freq[m];
        for(int i=0;i<10001;i++)
            freq[i]=0;
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==1)
                arr.push_back(nums[i]);
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n==0)
            return 0;
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        dp[0][1]=freq[arr[0]]*arr[0];
        for(int i=1;i<n;i++){
            
            int x=freq[arr[i]]*arr[i];
            dp[i][1]=0;
            dp[i][0]=0;
            for(int j=i-1;j>=0;j--){
                if(arr[i]-1!=arr[j]){
                    dp[i][1]=max(dp[j][1]+x,dp[i][1]);
                }
                dp[i][1]=max(dp[i][1],x+dp[j][0]);
                dp[i][0]=max(dp[j][0],dp[j][1]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};
