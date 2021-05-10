class Solution {
public:
    vector<string> ans;
    int n;
    string a;
    void func(int i,string &res,stack<int> &s){
        if(i==n){
            if(s.empty())
                ans.push_back(res);
            return ;
        }
        if(a[i]!='('&&a[i]!=')')
        {
            res+=a[i];
            func(i+1,res,s);
            res.pop_back();
        }
        else{
            if(a[i]=='('){
                func(i+1,res,s);
                res+=a[i];
                s.push('(');
                func(i+1,res,s);
                s.pop();
                res.pop_back();
                
            }
            else{
                func(i+1,res,s);
                if(!s.empty()&&s.top()=='('){
                    res+=a[i];
                    s.pop();
                    func(i+1,res,s);
                    s.push('(');
                    res.pop_back();
                }                
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        a=s;
        n=s.length();
        string q="";
        stack<int> p;
        vector<string> res;
        func(0,q,p);
        int maxi=0;
        unordered_map<string,int> m;
        for(auto i:ans){
            maxi=max(maxi,(int)i.length());
        }
        for(auto i:ans){
            if(i.length()==maxi&&m[i]!=1){
                res.push_back(i);
                m[i]=1;
            }
                
        }
        return res;
    }
};
