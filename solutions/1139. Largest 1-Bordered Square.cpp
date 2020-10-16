class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int m=arr[0].size();
        if(m==0)
            return 0;
        int left[n][m],right[n][m],up[n][m],down[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    left[i][j]=arr[i][j];
                }
                else{
                    if(arr[i][j]==0)
                        left[i][j]=0;
                    else
                        left[i][j]=left[i][j-1]+1;
                }
                    
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    up[i][j]=arr[i][j];
                }
                else{
                    if(arr[i][j]==0)
                        up[i][j]=0;
                    else
                        up[i][j]=up[i-1][j]+1;
                }
                    
            }
        }
        for(int i=n-1;i>=0;i--){
