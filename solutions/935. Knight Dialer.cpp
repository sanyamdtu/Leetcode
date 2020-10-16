int dp[5][5][5000];
int mod=1000000007;
class Solution {
public:
    
    int func(int n,int i,int j){
        if(i<0||j<0||i>3||j>=3||(i==3&&j==0)||(i==3&&j==2))
            return 0;
        if(n==0)
            return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int ans=0;
        int x[8] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
        int y[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
        for(int k=0;k<8;k++){
            
            int e=func(n-1,i+x[k],j+y[k]);
            if(e!=0){
                ans=(ans+e)%mod;
                
                // cout<<"pop "<<k<<" ";
            }
                
        }
        return dp[i][j][n]=ans;
    }
    int knightDialer(int n) {
        int a=0;
        memset(dp,-1,sizeof(dp));
          for(int i=0;i<4;i++){
              for(int j=0;j<3;j++){
                  // cout<<i<<" "<<j<<" "<<func(n-1,i,j)<<endl;
                 a=(a+func(n-1,i,j) )%mod ;
              }
          }  
        return a;
    }
};
