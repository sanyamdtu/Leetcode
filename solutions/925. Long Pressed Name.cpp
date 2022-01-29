class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int i=0,j=0;
        int n=s.length(),m=t.length();
        while(i<n&&j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if(j>0&&t[j]==t[j-1]){
                j++;
            }
            else
                return false;
        }
        while(j<m&&t[j]==t[j-1])
            j++;
        return (i==n&&j==m);
    }
};
