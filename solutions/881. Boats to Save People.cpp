class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for(int i=0,j=n-1;i<=j;){
            ans++;
             if(arr[i]+arr[j]<=limit)
             {
                 i++;
                 j--;
             }
            else
            {
                j--;
            }
        }
        return ans;
    }
};
