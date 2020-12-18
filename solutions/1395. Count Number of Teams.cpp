class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n=arr.size();
        int dp[n],a[n];
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[i]+=(arr[i]>arr[j]);
                a[i]+=(arr[i]<arr[j]);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])
                    ans+=dp[j];
                else if(arr[i]<arr[j])
                    ans+=a[j];
                
            }
        }
        return ans;
    }
};
