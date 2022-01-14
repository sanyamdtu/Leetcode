bool dp[3000][3000];
class Solution {
public:
    bool canCross(vector<int>& arr){
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[arr[i]]=i+1;
        int dx[]={-1,0,1};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=false;
        dp[0][0]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!dp[i][j])
                    continue;
                // cout<<i<<" "<<j<<endl;
                for(int k=0;k<3;k++){
                    int x=j+dx[k];
                    if(x>0&&m[arr[i]+x]>0){
                        int idx=m[arr[i]+x]-1;
                        dp[idx][x]=true;
                    }
                }
            }
        }
        bool ans=false;
        for(int j=0;j<n;j++)
            ans=(ans||dp[n-1][j]);
        return ans;
        
    }
};
