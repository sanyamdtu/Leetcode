class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n=arr.size();
        queue<pair<int,int>> q;
        int dist[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
                    
            }
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            for(int i=0;i<4;i++){
                int p= x+dx[i];
                int qw= y+dy[i];
                if(p>=0&&qw>=0&&p<n&&qw<n&&arr[p][qw]==0&&dist[p][qw]>dist[x][y]+1){
                    dist[p][qw]=dist[x][y]+1;
                    q.push({p,qw});
                }
            }
        }
        int a=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            a=max(a,dist[i][j]);
        }
        if(a==0||a==INT_MAX)
            return -1;
        return a;
    }
};
