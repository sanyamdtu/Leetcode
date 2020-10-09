class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(m==0&&n==0)
            return true;
        if(n>m)
            return false;
        int i=0, j=0;
        for(;i<n&&j<m;j++){
            if(s[i]==t[j])
                i++;
        }
        if(i==n)
            return true;
        return false;
        
    }
};
