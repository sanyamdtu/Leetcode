bool comp(vector<int> &a,vector<int> &b){
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}
int search(vector<int>&arr,int v){
    return lower_bound(arr.begin(),arr.end(),v)-arr.begin();
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int c=2;
        vector<int> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int s=arr[i][0];
            int e=arr[i][1];
            int idx=search(v,s);
            if(idx==v.size()){
                v.push_back(e-1);
                v.push_back(e);
            }
            else if(idx==v.size()-1){
                if(v[idx]<e)
                    v.push_back(e);
                else{
                    v.pop_back();
                    v.push_back(e-1);
                    v.push_back(e);
                }
            }
            // for(auto i:v)
            //     cout<<i<<" ";
            // cout<<endl;
        }
        return v.size();
    }
};
