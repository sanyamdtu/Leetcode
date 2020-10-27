class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        int n=a.size();
        stack<int> s;
        int f=0;
        for(int i=0,j=0;i<n;i++){
            s.push(a[i]);
            while(!s.empty()&&s.top()==b[j]){
                // cout<<"pop";
                j++;
                s.pop();
            }
            
        }
        return s.empty();
    }
};
