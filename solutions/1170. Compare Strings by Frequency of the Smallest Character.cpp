class Solution {
public:
    int func(string &s){
        int n=s.length();
        char ch=s[0];
        for(int i=0;i<n;i++){
            ch=min(ch,s[i]);
        }
        int f=0;
        for(auto i:s){
            if(i==ch)
                f++;
        }
        return f;
    }
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> v;
        int n=w.size();
        for(auto i:w){
            v.push_back(func(i));
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto i:q){
            int idx=lower_bound(v.begin(),v.end(),func(i)+1)-v.begin();
            int res=n-idx;
            ans.push_back(res);
        }
        return ans;
    }
};
