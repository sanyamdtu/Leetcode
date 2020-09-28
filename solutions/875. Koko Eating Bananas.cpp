#define pb push_back
typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        ll last=0;
        for(auto i:arr)
            last=max(last,(ll)i);
        ll beg=1,ans=INT_MAX;
        while(beg<=last){
            ll mid=(beg+last)/2;
            ll curr=0;
            for(int i:arr){
                curr+=(i+mid-1)/mid;
            }
            if(curr<=h){
                ans=min(mid,ans);
                last=mid-1;
            }
            else
                beg=mid+1;
        }
        return ans;
    }
};
