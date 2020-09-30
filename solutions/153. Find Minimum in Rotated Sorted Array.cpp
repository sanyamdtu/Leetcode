class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        // int arr[n];
        // for(int i=0;i<n;i++)
        //     arr[i]=nums[i];
         int i=0,beg=0,last=n-1,ans=INT_MAX;
        while(beg<=last){
            int mid=(beg+last)/2;
            if(arr[mid]>=arr[0]&&arr[mid]<=arr[n-1]){
                ans=min(ans,arr[mid]);
                last=mid-1;
            }
            else if(arr[mid]>=arr[0]&&arr[mid]>=arr[n-1]){
                beg=mid+1;
            }
            else 
            {
                ans=min(ans,arr[mid]);
                last=mid-1;
            }
        }
        return ans;
    }
};
