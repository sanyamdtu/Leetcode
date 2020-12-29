class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int dist[n][n];
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        int ans=-1;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            for(int i=0;i<4;i++){
                int p=x+dx[i];
                int qq=y+dy[i];
                if(p>=0&&qq>=0&&p<n&&qq<n&&arr[p][qq]==0){
                    arr[p][qq]=1;
                    dist[p][qq]=1+dist[x][y];
                    ans=max(dist[p][qq],ans);
                    q.push({p,qq});
                }
            }
        }
        return ans;
    }
};
