class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int ds[n],db[n],mini=arr[0];
        ds[0]=0;
        for(int i=1;i<n;i++){
            ds[i]=ds[i-1];
            ds[i]=max(ds[i],arr[i]-mini);
            mini=min(mini,arr[i]);
        }
        db[n-1]=0;
        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--){
            db[i]=db[i+1];
            db[i]=max(db[i],maxi-arr[i]);
            maxi=max(arr[i],maxi);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int a=ds[i];
            int b=0;
            if(i+1<n)
                b=db[i+1];
            ans=max(ans,a+b);
        }
        return ans;
    }
};
