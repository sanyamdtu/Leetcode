class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n=arr.size();
        if(k==1)
            return true;
        if(n%k!=0)
            return false;
        int c=n/k;
        sort(arr.begin(),arr.end());
        unordered_map<int,vector<int>> m;
        int ans=0;
        for(int i=0;i<n;i++){
            if(m[arr[i]-1].size()>0){
                int c=m[arr[i]-1].back();
                m[arr[i]-1].pop_back();
                if(c+1==k)
                    ans++;
                else
                    m[arr[i]].push_back(c+1);
            }
            else{
                m[arr[i]].push_back(1);
            }
        }
        
        for(auto i:m){
            for(auto j:i.second){
                if(j==k)
                    ans++;
                else
                    return false;
            }
        }
        return true;
    }
};
