bool comp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n=arr.size();
        int c=0,r=arr[n-1][1];
        for(int i=n-1;i>=0;i--){
            // cout<<arr[i][0]<<" ";
            if(r>arr[i][1]){
                c++;
            }
            r=max(r,arr[i][1]);
        }
        // cout<<endl;
        return c;
        
        
    }
};
