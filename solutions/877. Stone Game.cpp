class Solution {
public:
    
    // int func(vector<int> arr,int n,int s,int e,int f=0){
    //     if(s>e)
    //         return 0;
    //     if(s==e){
    //         if(f==0)
    //             return arr[s];
    //         else 
    //             return -arr[s];
    //     }
    //     if(dp[s][e][f]!=INT_MAX)
    //         return dp[s][e][f];
    //     if(f==0){
    //         return dp[s][e][f]=max(func(arr,n,s+1,e,1-f)+arr[s],func(arr,n,s,e-1,1-f)+arr[e]);
    //     }
    //     else{
    //         return dp[s][e][f]=min(func(arr,n,s+1,e,1-f)-arr[s],func(arr,n,s,e-1,1-f)-arr[e]);
    //     }
    // }
    bool stoneGame(vector<int>& g) {
        int n=g.size();
        int dp[600][600];
        for(int i=0;i<600;i++){
            for(int j=0;j<600;j++)
                dp[i][j]=0,dp[i][j]=0;
            
        }
        int arr[n+2];
        for(int i=1;i<=n;i++)
            arr[i]=g[i-1];
        arr[n+1]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-j+1;j++){
                dp[j][j+i-1]=max(arr[j]-dp[j+1][j+i-1],arr[j+i-1]-dp[i][j+i-2]);
            }
        }
        return dp[0][n-1]>0;
        // return func(arr,n,0,n-1)>0;
    }
};
