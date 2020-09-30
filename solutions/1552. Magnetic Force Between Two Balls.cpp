typedef long long ll;
class Solution {
public:
    ll func(ll arr[],ll n,ll k){
        ll p=0,c=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]-c>=k){
                p++;
                c=arr[i];
            }
        }
        return p;
    }
    int maxDistance(vector<int>& p, int m) {
        int n=p.size();
        ll arr[n];
        for(int i=0;i<n;i++)
            arr[i]=p[i];
        ll beg=1,last=1000000000,ans=-1;
        sort(arr,arr+n);
        while(beg<=last){
            ll mid=(beg+last)/2;
            // cout<<mid<<" ";
            if(func(arr,n,mid)>=m){
                ans=max(ans,mid);
                beg=mid+1;
            }
            else
                last=mid-1;
        }
        return ans;
    }
};
