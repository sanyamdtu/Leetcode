class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n);
        if(n==0)
            return v;
        stack<pair<int,int>> s; 
        s.push({arr[0],0});
        for(int i=1;i<n;i++){
            if(!s.empty()){
                auto a=s.top();
                while(!s.empty()&&arr[i]>a.first){
                    v[a.second]=i-a.second;
                    s.pop();
                    if(!s.empty())
                        a=s.top();
                }
            }
            s.push({arr[i],i});
        }
        while(!s.empty()){
            auto a=s.top();
                s.pop();
            v[a.second]=0;
        }
        return v;
    }
};
