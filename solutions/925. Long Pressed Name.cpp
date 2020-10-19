class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int i=1,j=1,f=0;
        int n=s.length(),m=t.length();
        if(s[0]!=t[0])
            f=1;
        while(i<n&&j<m&&f==0){
            cout<<i<<" "<<j<<endl;
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                if(t[j]==t[j-1]){
                    j++;
                }
                else
                    f=1;
            }
        }
        cout<<j;
        while(j<m&&t[j]==t[j-1])
            j++;
        if(i!=n||j!=m)
            f=1;
        if(f==1)
            return false;
        return true;
    }
};
