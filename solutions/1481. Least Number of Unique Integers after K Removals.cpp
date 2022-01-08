class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& num, int k) {
        unordered_map<int,int> m;
        for(auto i:num)
            m[i]++;
        vector<int> arr;
        for(auto i:m){
            arr.push_back(i.second);
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n&&k>0;i++){
            int  p=min(arr[i],k);
            if(arr[i]<=k)
                arr[i]=0;
            k-=p;
        }
        int c=0;
        for(int i=0;i<n;i++){
           
            if(arr[i]>0)
                c++;
        }
        // cout<<endl;
        return c;
    }
};
