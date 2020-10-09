class Solution {
public:
    int dp[600][600][2];
    int func(vector<int> arr,int n,int s,int e,int f=0){
        if(s>e)
            return 0;
        if(s==e){
            if(f==0)
                return arr[s];
            else 
                return -arr[s];
        }
        if(dp[s][e][f]!=INT_MAX)
            return dp[s][e][f];
        if(f==0){
            return dp[s][e][f]=max(func(arr,n,s+1,e,1-f)+arr[s],func(arr,n,s,e-1,1-f)+arr[e]);
        }
        else{
            return dp[s][e][f]=min(func(arr,n,s+1,e,1-f)-arr[s],func(arr,n,s,e-1,1-f)-arr[e]);
        }
    }
    bool stoneGame(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<600;i++){
            for(int j=0;j<600;j++)
                dp[i][j][0]=INT_MAX,dp[i][j][1]=INT_MAX;
            
        }
        return func(arr,n,0,n-1)>0;
    }
};
