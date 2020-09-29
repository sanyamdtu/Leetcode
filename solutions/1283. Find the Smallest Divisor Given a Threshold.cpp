class Solution {
public:
    int smallestDivisor(vector<int>& nums, int h) {
        int n=nums.size();
        int beg=1,last=10000000,ans=10000000;
        while(beg<=last){
            int mid=(beg+last)/2;
            cout<<mid<<" ";
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=h){
                ans=min(ans,mid);
                last=mid-1;
            }
            else
                beg=mid+1;
        }
        return ans;
    }
};
