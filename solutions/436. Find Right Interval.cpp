#define pb push_back
struct node {
        int s,e,i;
    };
bool comp(node a,node b){
        if(a.s==b.s)
            return a.e<b.e;
        return a.s<b.s;
    }
class Solution {
   
    
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
       
        int n=in.size();
         vector<int> v(n);
        node arr[n];
        for(int i=0;i<n;i++){
            arr[i].s=in[i][0];
            arr[i].e=in[i][1];
            arr[i].i=i;
        }
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++){
            int beg=i+1,last=n-1,ans=INT_MAX;
            while(beg<=last){
               int mid=(beg+last)/2;
                if(arr[mid].s>=arr[i].e){
                    ans=min(ans,mid);
