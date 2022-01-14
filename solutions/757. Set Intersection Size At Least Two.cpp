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
        int c=0;
        vector<int> v;
        int n=arr.size();
        int a=-1,b=-1;
        for(int i=0;i<n;i++){
            int s=arr[i][0];
            int e=arr[i][1];
            if(b<s){
                c+=2;
                a=e-1;
                b=e;
            }
            else if(a>=s&&b<=e)
                continue;
            else{
                if(b<e){
                    a=b;
                    b=e;
                    c++;
                }
                else{
                   a=e-1;
                    b=e;
                    c++;
                }
            }
        }
        return c;
    }
};
