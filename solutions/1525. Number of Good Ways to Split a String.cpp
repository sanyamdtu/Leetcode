class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        unordered_map<int,int> m,p;
        int b=0,curr=0;
        for(auto i:s){
            m[i]++;
        }
        b=m.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            m[s[i]]--;
            p[s[i]]++;
            if(p[s[i]]==1)
                curr++;
            if(m[s[i]]==0)
                b--;
            if(b==curr)
                ans++;
        }
        return ans;
    }
};
