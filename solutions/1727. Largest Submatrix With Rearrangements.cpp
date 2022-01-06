class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>0)
                    arr[i][j]+=arr[i-1][j];
            }
        }
        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end(),greater<int>());
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<arr[i][j]<<" ";
                ans=max(ans,arr[i][j]*(j+1));
            }
            // cout<<endl;
        }
        return ans;
    }
};
