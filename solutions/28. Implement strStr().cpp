class Solution {
public:
    int strStr(string t, string s) {
        if(t==s)
            return 0;
        if(t=="")
            return -1;
        if(s=="")
            return 0;
        
    int n=s.length(); 
    vector<int> lps(n,0);
    
    for (int i = 1,j=0; i < n; )
    {
        if(s[i]==s[j]){
            lps[i++]=++j;
        }
        else if(j>0){
            j=lps[j-1];
        }
        else{
            lps[i++]=0;
        }
    }
    // for(auto i:lps)
    //  cout<<i<<" ";
    int m=t.length();
    int ans=-1;
    for (int i = 0,j=0; i < m;)
    {
        if(t[i]==s[j]){
            i++,j++;
        }
        if(j==n)
        {
            ans=i-j;
            break;
        }
        else if(i<m&&t[i]!=s[j])
            (j>0)?j=lps[j-1]:i++;
    }
    return ans;
    }
​
};
