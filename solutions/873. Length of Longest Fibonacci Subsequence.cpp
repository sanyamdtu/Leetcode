class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        map<pair<int,int>,int> dp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                dp[{arr[i],arr[j]}]=1;
        }
        for(int i)
};
