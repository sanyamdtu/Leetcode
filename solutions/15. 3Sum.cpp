class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> v;
        map<pair<int,int>,bool> m;
        int n=arr.size();
        if(n<=2)
            return v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i==0||arr[i]!=arr[i-1])
            for(int j=i+1,k=n-1;j<k;){
                int sum=arr[i]+arr[j]+arr[k];               
                if(sum==0){
                    vector<int> s;
                    s.push_back(arr[i]);
                    s.push_back(arr[j]);
                    s.push_back(arr[k]);
                    if(!m[{arr[j],arr[k]}])
                        v.push_back(s);
                    m[{arr[j],arr[k]}]=true;
                    j++;
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else
                    j++;
            }
        }
        return v;
    }
};
