class Solution {
public:
    bool isTransformable(string s, string t) {
        int f=0,n=s.length();
        unordered_map<char,int> m,p;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(auto i:t){
            p[i]++;
        }
        for(auto i:m){
            if(p[i.first]!=i.second)
                f=1;
        }
        for(auto i:p){
            if(m[i.first]!=i.second)
                f=1;
        }
        if(f==1)
            return false;
        map<char,vector<int>> ma;
        for(int i=n-1;i>=0;i--){
            ma[s[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            int d=t[i]-'0';
            int idx=ma[t[i]].back();
            
            ma[t[i]].pop_back();
            for(int j=0;j<=d;j++){
                char ch='0'+j;
                // if(!ma[ch].empty())
                //     cout<<j<<" -> "<<ma[ch].back()<<endl;
                 if(!ma[ch].empty()&&ma[ch].back()<idx)
                     return false;
            }
            // cout<<endl;
        }
        return true;
    }
};
// "84532"
// "34852"
// "34521"
// "23415"
// "12345"
// "12435"
