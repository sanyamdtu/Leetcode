class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        int ans=0,r=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(s[i+1]==')'){
                    ans+=1<<r;
                    i++;
                }
                else
                    r++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
