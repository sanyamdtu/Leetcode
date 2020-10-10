 int dp[200][200][2][500];
class Solution {
public:
    int n;
    int arr[200];
   
    int func(int s,int e,int f,int m){
        if(s>e)
            return 0;
        if(s==e){
            if(f==0)
                return arr[s];
            else 
                return 0;
        }
        if(dp[s][e][f][m]!=-1)
            return dp[s][e][f][m];
        int ans,d=0;
        (f==0)?ans=INT_MIN:ans=INT_MAX;
        for(int i=s;i<=e&&i<s+2*m;i++){
            d+=arr[i];
            (f==0)?ans=max(d+func(i+1,e,1-f,max(m,i-s+1)),ans):
            ans=min(func(i+1,e,1-f,max(m,i-s+1)),ans);
        }
        return dp[s][e][f][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
      n=piles.size();
        memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++){
          arr[i]=piles[i];
      }
        return func(0,n-1,0,1);
    }
};
