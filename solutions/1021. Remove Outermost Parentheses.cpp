class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="",curr="";
        int n=s.length();
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(!stk.empty()&&s[i]==')'&&stk.top()=='(')
                {
                    stk.pop();
                }
            else{
                stk.push(s[i]);
            }
            curr+=s[i];
            // cout<<stk.top()<<endl;;
            if(stk.empty()){
                int a=curr.length();
                if(a>2)
                    ans+=curr.substr(1,a-2);
                curr="";
            }
        }
        return ans;
    }
};
