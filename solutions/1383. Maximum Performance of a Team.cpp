}
class Solution {
public:
    ll mod;
    int maxPerformance(int n, vector<int>& speed, vector<int>& ef, int k) {
        node arr[n];
        mod=1000*1000*1000;
        mod+=7;
        for(int i=0;i<n;i++){
            arr[i].s=speed[i];
            arr[i].e=ef[i];
        }
        sort(arr,arr+n,comp);
        ll ans=0,sum=0,mine;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<k;i++){
            sum=sum+arr[i].s;
            mine=arr[i].e;
            ans=max(ans,sum*mine);
            q.push(arr[i].s);
        }
        for(int i=k;i<n;i++){
            if(arr[i].s>q.top()){
                sum+=arr[i].s-q.top();
                mine=arr[i].e;
                q.pop();
                q.push(arr[i].s);
                ans=max(ans,sum*mine);
            }
            
        }
        cout<<ans;
        return ans % (int)(1e9+7);
    }
};
