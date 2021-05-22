class Solution {
public:
    unordered_map<string,int> m;
    string s;
    int n,dp[500];
    bool func(int i){
        if(i==n)
            return true;
        if(dp[i]!=-1)
            return (dp[i]==1);
        string a="";
        for(int j=i;j<n;j++){
            a+=s[j];
            if(m[a]==1)
            {
                if(func(j+1)){
                    dp[i]=1;
                    return true;
                }
                    
            }
        }
        dp[i]=0;
        return false;
    }
    bool wordBreak(string a, vector<string>& p) {
        m.clear();
        s=a;
        n=a.length();
        for(auto i:p)
            m[i]=1;
        memset(dp,-1,sizeof(dp));
        return func(0);
    }
};
