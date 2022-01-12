bool comp(vector<int>&a,vector<int>&b){
    if(a[1]-a[0]==b[1]-b[0])
        return a[1]>b[1];
    return a[1]-a[0]>b[1]-b[0];
    
}
class Solution {
public:
    int minimumEffort(vector<vector<int>>& arr) {
        int n=arr.size();
        int lo=0,hi=INT_MAX,res=INT_MAX;
        sort(arr.begin(),arr.end(),comp);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int c=mid,p=0;
            for(int i=0;i<n;i++){
                if(arr[i][1]<=c){
                    c-=arr[i][0];
                    p++;
                }
                else
                    break;
            }
            if(p==n){
                res=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return res;
    }
};
