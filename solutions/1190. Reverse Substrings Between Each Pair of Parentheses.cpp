class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<string> stk;
        string res="",curr="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(curr);
                curr="";
            }
            else if(s[i]==')'){
                reverse(curr.begin(),curr.end());
                 curr=stk.top()+curr;
                stk.pop();
            }
            else{
                curr+=s[i];
            }
        }
        return curr;
    }
};
