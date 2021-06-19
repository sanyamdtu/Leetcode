class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> s;
        int res=0;
        for(auto i:arr){
            while(!s.empty()&&s.top()<=i){
                int a=s.top();
                s.pop();
                int c=INT_MAX;
                if(!s.empty())
                    c=s.top();
                res+=a*min(c,i);
            }
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            res+=a*s.top();
        }
        return res;
    }
};
