class Solution {
public:
    int n;
    int m;
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        n=arr.size();
        m=arr[0].size();
        // cout<<m<<" "<<n;
        vector<vector<int>>v(n,vector<int>(m));
        int dist[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                dist[i][j]=INT_MAX;
        }
        queue<pair<int,int>>q ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
                    
            }
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=a.first+dx[i];
                int y=a.second+dy[i];
                if(x>=0&&y>=0&&x<n&&y<m)
                if(dist[a.first][a.second]+1<dist[x][y]){
                    dist[x][y]=dist[a.first][a.second]+1;
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j]=dist[i][j];
            }
        }
        return v;
    }
};
