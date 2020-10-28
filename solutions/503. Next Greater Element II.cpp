class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        stack<int> s;
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            s.push(arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==maxi){
                v[i]=-1;
                s.push(arr[i]);
            }
                
            else{
                while(!s.empty()&&arr[i]>=s.top()){
                    s.pop();
                }
                if(!s.empty())
                    v[i]=s.top();
                else
                    v[i]=-1;
                s.push(arr[i]);
            }
        }
        return v;
    }
};
