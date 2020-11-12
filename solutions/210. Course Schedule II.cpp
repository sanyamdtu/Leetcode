class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        int in[n];
        memset(in,0,sizeof(in));
        for(auto i:arr)
            in[i[0]]++;
        vector<vector<int>>g(n); 
        for(auto i:arr){
            g[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> o;
        for(int i=0;i<n;i++){
            if(!in[i]){
                q.push(i);
                o.push_back(i);
            }
        }
        while(!q.empty()){
            int a =q.front();
            q.pop();
            for(auto i:g[a]){
                in[i]--;
                if(!in[i]){
                    q.push(i);
                    o.push_back(i);
                }
            }
        }
        vector<int> v;
        if(o.size()!=n)
            return v;
        return o;
    }
};
