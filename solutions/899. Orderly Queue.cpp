class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>=2){
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        int n=s.length();
        for(int i=0;i<n;i++){
            string p=s.substr(1)+s[0];
            s=p;
            if(ans>p)
                ans=p;
        }
        return ans;
    }
};
