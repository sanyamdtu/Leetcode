class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1,f=0;
        if(n<=1)
            return (n<=1);
        while(i<j&&f==0){
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else{
                if(tolower(s[i])!=tolower(s[j])){
                    f=1;
                    // cout<<i<<" "<<j<<endl;
                }
                    
                i++;
                j--;
            }
        }
        return f==0;
    }
};
