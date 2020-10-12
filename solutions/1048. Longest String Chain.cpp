bool comp(string a,string b)
    {
        return a.length()<b.length();
    }
class Solution {
public:
    
    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        unordered_map<string,int> m;
        int dp[n];
       for(int i=0;i<n;i++)
           dp[i]=1;
        for(int i=0;i<n;i++)
            m[arr[i]]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<arr[i].length();j++){
                if(m.find(arr[i].substr(0,j)+arr[i].substr(j+1))!=m.end())
                dp[i]=max(dp[i],dp[m[arr[i].substr(0,j)+arr[i].substr(j+1)]]+1);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
            // cout<<dp[i];;
        }
            
        return ans;
    }
};
