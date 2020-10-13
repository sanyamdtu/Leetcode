class Solution {
public:
    vector<int>arr;
    int n;
    int k;
    double dp[200][200];
    double func(int s,int c){
        
        if(c==k-1){
            if(s==n)
                return 0;
            double sum=0;
            for(double i=s;i<n;i++){
                sum+=arr[i];
            }    
            return (double)(sum/(n-s));
        }
        if(dp[s][c]!=-1)
            return dp[s][c];
        double ans=0,sum=0;
        // cout<<n;
        for(double i=s;i<n;i++){
            sum+=arr[i];
            double hi=sum/(i-s+1);
            ans=max(ans,hi+func(i+1,c+1));
            
        }
         return dp[s][c]=ans;
    }
    double largestSumOfAverages(vector<int>& a, int K) {
