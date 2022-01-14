struct node{
    int c,p;
};
bool comp(node &a,node &b){
    return a.c<b.c;
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& r) {
        int n=p.size();
        node arr[n];
        for(int i=0;i<n;i++){
            arr[i]={r[i],p[i]};
        }
        sort(arr,arr+n,comp);
        priority_queue<int> q;
        int ans=w,c=0;
        int i=0;
        while(i<n&&k>0){
            while(i<n && arr[i].c<=w){
                q.push(arr[i].p);
                i++;
            }
            if(q.empty())
                break;          
            k--;
            w+=q.top();
            q.pop();
            
        }
        while(!q.empty()&&k>0){
            k--;
            w+=q.top();
            q.pop();
        }
        return w;
    }
};
