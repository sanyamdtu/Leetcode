class Solution {
public:
    int minSubArrayLen(int s, vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            // cout<<arr[i]<<" ";
            if(arr[i]>=s)
                ans=min(ans,i+1);
            // cout<<ans<<" ";
        }
        for(int i=1;i<n;i++){
            int beg=i,last=n-1;
            while(beg<=last){
                int mid=(beg+last)/2;
                cout<<mid<<" ";
                if(arr[mid]-arr[i-1]>=s){
                    last=mid-1;
                    ans=min(mid-i+1,ans);
                }
                else{
                    beg=mid+1;
                }
            }      cout<<endl;          
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
