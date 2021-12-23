​
typedef long long ll;
class Solution {
public:
    int left[500000],right[500000];
    int maxTotalFruits(vector<vector<int>>&arr, int x, int k) {
        int idx=0,n=arr.size();
        set<ll> s;
        while(idx<n){
            if(arr[idx][0]>=x)
                break;
            idx++;
        }
        unordered_map<ll,ll> left,right;
        ll c=0;
        for(int i=idx;i<n;i++){
            s.insert(arr[i][0]);
            c+=arr[i][1];
            right[arr[i][0]]=c;
        }
        c=0;
        for(int i=idx-1;i>=0;i--){
            s.insert(arr[i][0]);
            c+=arr[i][1];
            left[arr[i][0]]=c;
        }
        ll ans=0;
        for(int i=idx;i<n;i++){
            ll pos=arr[i][0];
            ll dist=pos-x;
            ll c=pos-(k-dist);
            if(dist>k){
                break;
            }
            
            auto it=s.lower_bound(c);
            if(it==s.end())
                ans=max(ans,(ll)right[pos]);
            else
                ans=max(ans,right[pos]+left[*(it)]);
        }
        set<ll,greater<ll>> s2(s.begin(),s.end());
        for(int i=idx-1;i>=0;i--){
            ll pos=arr[i][0];
            ll dist=x-pos;
            ll c=pos+(k-dist);
            if(dist>k){
                break;
            }
            // cout<<left[pos]<<" "<<right[c]<<" ";
            auto it=s2.lower_bound(c);
            // cout<<(*(it));
            if(it==s2.end())
                ans=max(ans,(ll)left[pos]);
            else
                ans=max(ans,left[pos]+right[*(it)]);
        }
        
        return ans;
    }
};
