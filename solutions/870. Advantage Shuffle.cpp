typedef long long ll;
class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>&b) {
        sort(a.begin(),a.end());
        int n=a.size();
        
        multiset<ll> s;
        for(auto i:a){
            s.insert(i);
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            auto it=s.lower_bound(b[i]+1);
            if(it!=s.end()){
                res[i]=*(it);
                s.erase(it);
            }
            else{
                res[i]=*(s.begin());
                s.erase(s.begin());
            }
        }
        return res;
    }
};
