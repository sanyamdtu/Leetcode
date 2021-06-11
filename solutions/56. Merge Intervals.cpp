bool c(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),c);
        vector<vector<int>> ans;
        int a=arr[0][0],b=arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(b<arr[i][0]){
                ans.push_back({a,b});
                a=arr[i][0];
                b=arr[i][1];
            }
            else{
                b=max(arr[i][1],b);
            }
        }
        ans.push_back({a,b});
        return ans;
    }
};
