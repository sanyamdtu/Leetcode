class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,c=0,n=arr.size();
        for(int i=0;i<n;i++){
            c=max(arr[i],c);
            if(c==i)
                ans++;            
        }
        return ans;
    }
};
