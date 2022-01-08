class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        for(auto i:s)
            m[i]++;
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,c=v[0]-1;
        for(int i=1;i<v.size();i++){
            if(v[i]>c){
                ans+=v[i]-c;
                if(c>0)
                    c=c-1;
            }
            else{
                c=v[i]-1;
            }
        }
        return ans;
    }
};
