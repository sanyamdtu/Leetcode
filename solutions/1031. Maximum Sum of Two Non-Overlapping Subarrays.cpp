class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int l, int m) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        int ans=0,e=0,f=0;
        for(int i=l+m-1;i<n;i++){
            int a=arr[i]-arr[i-l];
            int b=arr[i-l];
            if(i-l-m>=0)       
                b=arr[i-l]-arr[i-l-m];
            int c=arr[i]-arr[i-m];
            int d=arr[i-m];
            if(i-l-m>=0)       
                d=arr[i-m]-arr[i-l-m];
            e=max(e,b);
            f=max(f,d);
            ans=max(ans,a+e);
            ans=max(ans,c+f);
        }
        return ans;
    }
};
