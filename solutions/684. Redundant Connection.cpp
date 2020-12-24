class Solution {
public:
    int find(int x,int p[]){
        if(x==p[x])
            return x;
        return p[x]=find(p[x],p);
    }
    void un(int x,int y,int p[],int r[]){
        int px=find(x,p);
        int py=find(y,p);
        if(r[px]>r[py])
            p[py]=px;
        else if(r[px]<r[py])
            p[px]=py;
        else{
            p[px]=py;
            r[py]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int r[edges.size()+1],p[edges.size()+1];
        for(int i=0;i<edges.size()+1;i++)
        {
            r[i]=1;
            p[i]=i;
        }
        for(auto i:edges){
            if(find(i[0],p)==find(i[1],p))
                return i;
            else
                un(i[0],i[1],p,r);
        }
        vector<int> v;
        return v;
    }
};
