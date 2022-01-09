class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        int c=arr[0];
        for(int i=1;i<n;i++){
            // cout<<c<<" "<<arr[i]<<endl;
            if(arr[i]<=c){
                ans+=c+1-arr[i];
                c++;
            }
            else
                c=arr[i];
        }
        return ans;
    }
};
