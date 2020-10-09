class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
      int n=arr.size();
        if(n==1)
            return arr[0];
        int maxi=10000000000;
        maxi*=-1;
        int curr=0;
        for(int i=0;i<n;i++){
            if(curr+arr[i]<0){
                curr=0;
            }
            else
                curr+=arr[i];
            maxi=max(maxi,curr);
        }
        if(maxi==0)
        {
            int m=arr[0];
            for(int i=1;i<n;i++)
                m=max(arr[i],m);
            return m;
        }
        else
            return maxi;
    }
};
