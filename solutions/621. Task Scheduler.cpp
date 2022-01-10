struct node{
    // char ch;
    int v;
};
struct comp {
    bool operator() (node &a,node &b) {
        return a.v<b.v;
    }
};
​
class Solution {
public:
    int leastInterval(vector<char>& arr, int k) {
        int n=arr.size();
        unordered_map<char,int> m;
        for(auto i:arr){
            m[i]++;
        }
        priority_queue<int> q;
        for(auto i:m)
            q.push(i.second);
        int ans=0;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            ans++;
