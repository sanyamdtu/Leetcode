class Solution {
public:
    string removeDuplicates(string arr, int k) {
        stack<pair<char,int>> s;
        int n=arr.length();
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                s.push({arr[i],1});
            else{
                if(s.top().first==arr[i]){
                    s.top().second++;
                    if(s.top().second==k)
                     s.pop();
                }
                else{
                    s.push({arr[i],1});
                }
            }
        }
        string ans="";
        while(!s.empty()){
            while(s.top().second){
                ans+=s.top().first;
                s.top().second--;
            }
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
