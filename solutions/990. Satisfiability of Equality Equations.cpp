class Solution {
public:
    unordered_map<char,int> r;
    unordered_map<char,char> par;
    char find(char x)
    {
        if(x==par[x])
            return x;
        return par[x]=find(par[x]);
    }
    void un(char x,char y){
        char px=find(x);
        char py=find(y);
        if(px!=py){
            if(r[px]>r[py]){
                par[py]=px;
            }
            else if(r[px]<r[py]){
                par[px]=py;
            }
            else{
                par[px]=py;
                r[py]++;
            }
        }
    }
    bool equationsPossible(vector<string>& arr) {
        r.clear();
        par.clear();
        for(auto i:arr){
            if(r.find(i[0])==r.end()){
                r[i[0]]=1;
                par[i[0]]=i[0];
            }
            if(r.find(i[3])==r.end()){
                r[i[3]]=1;
                par[i[3]]=i[3];
            }
            if(i[1]=='=')
                un(i[0],i[3]);
        }
        for(auto i:arr){
            if(i[1]=='!'){
                if(find(i[0])==find(i[3]))
                    return false;
            }
        }
        return true;
    }
};
