class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n==1)
            return 0;
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++){
            int a=arr[n-1]-k;
            int b=arr[i+1]-k;
            int c=arr[0]+k;
            int d=arr[i]+k;
            int maxi=max(a,max(b,max(c,d)));
            int mini=min(a,min(b,min(c,d)));
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};
