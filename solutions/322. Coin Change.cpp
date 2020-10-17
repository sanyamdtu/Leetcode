int dp[50][120000];
class Solution {
public:
    int n;
    
    vector<int> arr;
    int func(int i,int sum){
       if(sum<=0){
          if(sum==0)
              return 0;
          else
                return 100000; 
       }
        if(i==n)
            return 100000;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        return dp[i][sum]=min(1+func(i,sum-arr[i]),func(i+1,sum));
    }
    int coinChange(vector<int>& a, int sum) {
        sort(a.begin(),a.end());
        arr=a;
        
        // cout<<arr.size();
        n=a.size();
        if(n==0)
            return 0;
       for(int i=0;i<50;i++){
           for(int j=0;j<120000;j++)
               dp[i][j]=-1;
       }
        int d=func(0,sum);
        if(d>=100000)
            return -1;
        return d;
    }
};
