class Solution {
public:
    int smallestDivisor(vector<int>& arr, int h) {
        int hi=1,lo=1,n=arr.size(),ans=INT_MAX;
        for(auto i:arr)
            hi=max(hi,i);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int d=0;
            for(auto i:arr)
                d+=(i+mid-1)/mid;
            if(d<=h)
            {
                hi=mid-1;
                ans=min(ans,mid);
            }
            else
                lo=mid+1;
        }
        return ans;
        
    }
};
