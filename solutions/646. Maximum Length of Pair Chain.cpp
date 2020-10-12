bool comp(vector<int> a,vector<int> b){
    return a[1]<b[1] ;
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        // int dp[n];
        sort(arr.begin(),arr.end(),comp);
        // set<pair<int,int>> s;
        int ans=1,p=arr[0][1];
        for(int i=1;i<n;i++){
            if(p<arr[i][0])
            {
                ans++;
                p=arr[i][1];
            }
        }
        return ans;
        
    }
};
