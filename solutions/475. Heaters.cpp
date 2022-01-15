class Solution {
public:
    int findRadius(vector<int>& arr, vector<int>& h) {
        sort(arr.begin(),arr.end());
        sort(h.begin(),h.end());
        int n=arr.size(),m=h.size();
        int lo=0,hi=0;
        for(auto i:h)
            hi=max(i,hi);
        for(auto i:arr)
            hi=max(hi,i);
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int i=0,j=0;
            for(;i<n&&j<m;){
                int s=h[j]-mid;
                int e=h[j]+mid;
                if(s<=arr[i]&&arr[i]<=e){
                    i++;
                }
                else{
                    j++;
                } 
            }
            // cout<<mid<<" "<<i<<endl;
            if(i==n){
