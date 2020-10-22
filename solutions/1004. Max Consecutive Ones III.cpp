class Solution {
public:
    int longestOnes(vector<int>&arr , int k) {
        int i=0,j=0,ans=0;
        int n=arr.size();
        for(;j<n;j++){
            if(arr[j]==0)
                k--;
            if(k<0&&arr[i++]==0)
                k++;
            if(k>=0)
                ans=max(ans,j-i+1);
        }
        return ans;
       
    }
};
