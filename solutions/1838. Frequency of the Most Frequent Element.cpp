class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        int ans=1;
        long long c=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int j=0,i=0;j<n;j++){
            if(j>0){
                c+=((long long)(arr[j]-arr[j-1]))*(j-i);
            }
            while(c>k){
                c-=arr[j]-arr[i];
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
