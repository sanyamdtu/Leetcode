class Solution {
public:
    int findRadius(vector<int>& arr, vector<int>& h) {
        sort(arr.begin(),arr.end());
        sort(h.begin(),h.end());
        int n=arr.size(),m=h.size();
        long long j=0,ans=0;
        long long a=INT_MIN,b=arr[0];
        int i=0;
        for(;i<n&&j<m;){
            b=h[j];
            if(b<arr[i]&&j!=m-1)
            {
                a=b;
                j++;
                continue;
            }         
            else{
                // cout<<a<<" "<<arr[i]<<" "<<b<<endl;
                 ans=max(ans,min(abs(arr[i]-a),abs(b-arr[i])));
                i++;
            }
        }
        return ans;
    }
};
