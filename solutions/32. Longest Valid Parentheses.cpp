class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),ans=0,curr=0,l=0;
        for(auto i:s){
            if(i=='('){
                curr++;
                l++;
            }
            else{
                curr--;
                l++;
                if(curr<0){
                    l=0;
                    curr=0;
                }
                if(curr==0)
                    ans=max(ans,l);
            }
        }
        curr=0,l=0;
        reverse(s.begin(),s.end());
        // cout<<s;
        for(auto i:s){
            if(i==')'){
                curr++;
                l++;
            }
            else{
                curr--;
                l++;
                if(curr<0){
                    l=0;
                    curr=0;
                }
                if(curr==0)
                    ans=max(ans,l);
            }
        }
        return ans;
    }
};
