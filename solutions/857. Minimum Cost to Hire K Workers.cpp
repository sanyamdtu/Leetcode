struct node{
    int q,w;
};
bool comp(node &a,node &b){
    return ((1.0*a.w)/ (1.0*a.q))<((1.0*b.w)/ (1.0*b.q));
}
struct compi{
    bool operator()(node &a,node &b){
        return a.q<b.q;
    }
};
class Solution {
public:
    double mincostToHireWorkers(vector<int>& oq, vector<int>& w, int k) {
        int n=oq.size();
        node arr[n];
        for(int i=0;i<n;i++)
            arr[i]={oq[i],w[i]};
        sort(arr,arr+n,comp);
        priority_queue<node,vector<node>,compi> q;
        double ans=INT_MAX,mine=0,c=0;
        for(int i=0;i<n;i++){
            if(q.size()==k){
                if(q.top().q>arr[i].q){
                    ans=min(ans,c*mine);
