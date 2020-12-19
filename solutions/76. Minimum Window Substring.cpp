class Solution {
public:
    string minWindow(string a, string b) {
        unordered_map<char,int> m;
        for(auto i:b){
            m[i]++;
        }
        int ans=INT_MAX,idx=-1;
        int n=a.length();
        for(int i=0,j=0;j<n;j++){
            int f=0;
            m[a[j]]--;
            for(auto k:m)
                if(k.second>0)
                    f=1;
            if(f!=1){
                for(;i<=j;i++){
                    if(m[a[i]]==0)
                        break;
                    else
                        m[a[i]]++;
                }
                if(ans>j-i+1){
                    ans=j-i+1;
                    idx=i;
                }
            }            
        }
        string res="";
        if(idx==-1)
            return res;
        for(int i=idx;i<idx+ans;i++)
            res+=a[i];
        return res;
    }
};
