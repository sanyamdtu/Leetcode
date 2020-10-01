class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int beg=0,last=n-1,ans=INT_MIN;
        while(beg<=last){
            int mid=(beg+last)/2;
            if(arr[mid]<=x){
                ans=max(ans,mid);
                beg=mid+1;
            }
            else
                last=mid-1;
        }
        if(ans==INT_MIN)
            ans=-1;
        int i=ans,j=ans+1;
        vector<int> v;
        while(i>=0&&j<n&&k){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                v.push_back(arr[i]);
                k--;
                i--;
            }
            else{
                v.push_back(arr[j]);
                k--;
                j++;
            }           
        }
