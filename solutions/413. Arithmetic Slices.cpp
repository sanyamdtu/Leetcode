int dp[5004][5005];
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        cout<<n;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n&&j<i+2;j++){
                dp[i][j]=1;
            }
        }
       for(int i=0;i<n;i++){
           for(int j=i+2;j<n;j++){
               if(arr[j]-arr[j-1]==arr[j-1]-arr[j-2]){
                   dp[i][j]=dp[i][j-1];
                   // cout<<i<<" "<<j<<endl;
               }
               else
                   dp[i][j]=0;
           }
       }
        int ans=0;
       for(int i=0;i<n;i++){
           for(int j=i+2;j<n;j++){
               ans+=dp[i][j];
               
           }
       }
       return ans;
        return 0;
       
    }
};
