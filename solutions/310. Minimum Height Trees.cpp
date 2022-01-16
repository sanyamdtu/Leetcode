class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        int node[n];
        memset(node,0,sizeof(node));
        for(auto i:edges){
            node[i[0]]++;
            node[i[1]]++;
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(node[i]<=1)
                q.push(i);
        vector<int> v;
        while(!q.empty()){
            int size=q.size();   
            v=vector<int>();
            while(size--){
                int a=q.front();
                v.push_back(a);
                q.pop();
                for(auto i:g[a]){
                    node[i]--;
                    if(node[i]==1)
                        q.push(i);
                }
            }
        }
        return v;
    }
};
