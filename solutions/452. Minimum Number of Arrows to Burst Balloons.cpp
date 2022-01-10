bool comp(vector<int> &a,vector<int>&b){
    if(a[1]==b[1])
        return a[0]>b[0];
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end(),comp);
        int e=arr[0][1];
        for(int i=1;i<n;i++){
            if(e<arr[i][0])
            {
                ans++;
                e=arr[i][1];
            }
        }
        ans++;
        return ans;
    }
};
