class Solution {
public:
    int n;
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return n;
        if(n==1)
            return arr[0][0];
        arr[1][0]+=arr[0][0];
        arr[1][1]+=arr[0][0];
        for(int i=2;i<n;i++){
            for(int j=0;j<arr[i].size();j++){
                if(j==0)
                    arr[i][0]+=(arr[i-1][0]);
                else if(j==arr[i].size()-1)
                    arr[i][j]+=arr[i-1][j-1];
                else
                arr[i][j]+=min(arr[i-1][j],arr[i-1][j-1]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<arr[n-1].size();i++){
            cout<<arr[n-1][i]<<" ";
            ans=min(ans,arr[n-1][i]);
        }
            
        return ans;
    }
};
