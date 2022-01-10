typedef long long ll;
struct node{
  ll d,p;
};
bool comp(node &a,node &b){
    if(a.d==b.d)
        return a.p<b.p;
    return a.d<b.d;
}
​
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        node arr[n];
        for(int i=0;i<n;i++){
            arr[i]={d[i],p[i]};
        }
        sort(arr,arr+n,comp);
        ll pre[n];
        pre[0]=arr[0].p;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],arr[i].p);
        }
        ll ans=0;
        for(auto i:w){
            int lo=0,hi=n-1;
            int idx=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(arr[mid].d<=i){
                    idx=mid;
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
            if(idx>=0){
                ans+=pre[idx];
            }
        }
        return ans;
    }
};
