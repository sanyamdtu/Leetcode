class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int i=0,j,curr=0;
        int ans=0;
        int n=arr.size();
        for(j=0;j<n;j++){
            if(curr==0)
                curr=1;
             curr=curr*arr[j];
            int len=(j-i+1);
            if(curr>=k){
                while(i<=j&&curr>=k){
                    curr=curr/(arr[i]);
                    i++;
                }
            }
            if(i<=j){
                ans+=(j-i+1);
            }
        }
        return ans;
    }
};
