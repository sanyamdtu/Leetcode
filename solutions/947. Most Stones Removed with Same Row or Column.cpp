class Solution {
public:
    int find(int x,unordered_map<int,int> &p){
        if(p[x]==x)
            return x;
        return p[x]=find(p[x],p);
    }
    void un(int x,int y,unordered_map<int,int> &p,unordered_map<int,int> &r){
        int px=find(x,p);
        int py=find(y,p);
        if(r[px]<r[py])
            p[px]=py;
        else if(r[px]>r[py])
            p[py]=px;
        else{
            p[px]=py;
            r[py]++;
        }
    }
    int removeStones(vector<vector<int>>& arr) {
        
        if(arr.size()==0)
            return 0;
        unordered_map<int,int> p,r;
        int c=0;
        for(auto i:arr){
​
            if(p[i[0]+1]==0){
                c++;
                p[i[0]+1]=i[0]+1;
            }     
            if(p[-i[1]-1]==0){
                c++;
                p[-i[1]-1]=-i[1]-1;
            }
            if(find(i[0]+1,p)!=find(-i[1]-1,p)){
                // cout<<find(i[0]+1,p)<<" "<<find(-i[1]-1,p)<<" ";
                un(i[0]+1,-i[1]-1,p,r);
                // cout<<find(i[0]+1,p)<<" "<<find(-i[1]-1,p)<<endl;
                c--;
            }
        }
        return arr.size()-c;
    }
};
