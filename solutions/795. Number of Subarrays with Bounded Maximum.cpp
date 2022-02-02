class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int l, int r) {
        int ans=0,i=0,j=0,n=arr.size();
        int x=0;
        for(j=0;j<n;j++){
            if(arr[j]<l){
                ans+=x;
            }
            else if(arr[j]<=r){
                ans+=j-i+1;
                x=j-i+1;
            }
            else{
                i=j+1;
                x=0;
            }
        }
        return ans;
    }
};
