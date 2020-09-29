class Solution {
public:
    bool func(int a,int arr[][400],int n,int m,int h){
        if(a==0)
            return true;
        int f=0;
        for(int i=0;i<=n-a;i++){
            for(int j=0;j<=m-a;j++){
                int sum=arr[i+a-1][j+a-1];
                if(i-1>=0)
                    sum-=arr[i-1][j-1+a];
                if(j-1>=0)
                    sum-=arr[i+a-1][j-1];
                if(i-1>=0&&j-1>=0)
                    sum+=arr[i-1][j-1];
                if(sum<=h){
                    f=1;
                }
            }
        }
        if(f==0)
            return false;
        else 
            return true;
    }
    int maxSideLength(vector<vector<int>> mat, int key) {
        int n=mat.size(),m;
        if(n==0)
            m=0;
        else
