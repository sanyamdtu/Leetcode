bool comp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n=arr.size();
        vector<vector<int>> ans(n);
        int vis[n];
        memset(vis,-1,sizeof(vis));
        // for(auto i:arr)
        //     cout<<i[0]<<" "<<i[1]<<endl;
        for(int i=0;i<n;i++){
            int c=arr[i][1];
            int idx=0;
            while(c>0){
                if(vis[idx]==-1||vis[idx]==arr[i][0])
                    c--;
                idx++;
            }
            while(vis[idx]>-1)
                idx++;
            // cout<<idx<<" ";
            vis[idx]=arr[i][0];
            ans[idx]=arr[i];
            // for(int j=0;j<n;j++)
            //     cout<<vis[j]<<" ";
            // cout<<endl;
        }
        return ans;
    }
};
