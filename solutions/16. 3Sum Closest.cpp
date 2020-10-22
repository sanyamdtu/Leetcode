class Solution {
public:
    int threeSumClosest(vector<int>& arr, int t) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=100000;
        cout<<n;
        for(int i=0;i<n;i++){
            for(int j=0,k=n-1;j<k;){
                    int sum=arr[i]+arr[j]+arr[k];
                    if(sum>t){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        if(i!=j&&i!=k)
                        if(sum-t<abs(t-ans))
                            ans=sum;
                        k--;
                    }
                    else
                    {
                        
                            // cout<<abs(sum-ans);
                        if(i!=j&&i!=k)
                        if(t-sum<abs(t-ans))
                            ans=sum;
                        j++;
                    }
            }
        }
        return ans;
    }
};
