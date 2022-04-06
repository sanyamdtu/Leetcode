class Solution {
public:
    int minNumberOperations(vector<int>& arr) {
        arr.push_back(0);
        int n=arr.size();
        int ans=0;
        int a=arr[0];
        for(int i=1;i<n;i++){
            if(a>arr[i]){
                ans+=a-arr[i];
                a=arr[i];
            }
            else if(a<arr[i]){
                a=arr[i];
            }
        }
        ans+=a;
        return ans;
    }
};
