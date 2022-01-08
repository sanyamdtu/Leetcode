typedef long long ll;
class Solution {
public:
    ll mod;
    int maxSumRangeQuery(vector<int>& arr, vector<vector<int>>& p) {
        mod=1000*1000*1000;
        mod+=7;
        int n=arr.size();
        ll vis[n+1];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<p.size();i++){
            vis[p[i][0]]++;
            vis[p[i][1]+1]--;
        }
        for(int i=1;i<n+1;i++){
            vis[i]+=vis[i-1];
        }
        sort(vis,vis+n,greater<int>());
        ll ans=0;
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<n;i++){
            ll e=((ll)arr[i]* (ll)vis[i])%mod;
            ans=(ans+e)%mod;
        }
        return ans;
    }
};
