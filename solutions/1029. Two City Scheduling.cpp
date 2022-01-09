bool comp(vector<int>&a,vector<int>&b){
    return (a[0]-a[1]<b[0]-b[1]);
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int ans=0;
        for(int i=0,j=arr.size()-1;i<j;i++,j--){
            ans+=arr[i][0];
            ans+=arr[j][1];
        }
        return ans;
    }
};
