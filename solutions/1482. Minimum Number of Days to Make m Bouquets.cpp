typedef long long ll;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
         int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=bloomDay[i];
        ll beg=0,last=1000000000,ans=INT_MAX;
        while(beg<=last){
            ll mid=(beg+last)/2;
            int curr=0,p=0;
            for(int i=0;i<n;i++){
                if(arr[i]<=mid){
                    curr++;
                    if(curr==k)
                    {
                        curr=0;
                        p++;
                    }
                }
                else
                    curr=0;
            }
            if(p>=m){
                ans=min(ans,mid);
                last=mid-1;
            }
                
            else
                beg=mid+1;
                
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
