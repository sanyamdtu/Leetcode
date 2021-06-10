class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        n=s.length();
        int i=n-1;
        int f[10];
        memset(f,-1,sizeof(f));
        for(;i>=0;i--){
            for(int j=s[i]-'0'+1;j<=9;j++){
                if(f[j]>=0){
                    swap(s[f[j]],s[i]);
                    sort(s.begin()+i+1,s.end());
                    if(stoll(s)>INT_MAX)
                        return -1;
                    return stoll(s);
                    
                }
                // cout<<endl;
               
            }
             f[s[i]-'0']=i;
        }
        return -1;
    }
};
