class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>arr) {
        sort(arr.begin(),arr.end());
        long long c=mass;
        for(int i=0;i<arr.size();i++){
            // cout<<arr[i]<<" ";
            if(c<arr[i])
                return false;
            c+=arr[i];
            // cout<<c<<" ";
        }
        return true;
    }
};
