class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        queue<pair<int,int>> q;
        int dist[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==2){
                    q.push({i,j});
                    dist[i][j]=0;
                }
                else
                    dist[i][j]=INT_MAX; 
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
                int c=x+dx[i];
                int d=y+dy[i];
                if(c>=0&&d>=0&&c<n&&d<m&&arr[c][d]==1&&dist[c][d]==INT_MAX){
                    q.push({c,d});
                    dist[c][d]=dist[x][y]+1;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)
                    c=max(dist[i][j],c);
            }
        }
        if(c==INT_MAX)
            return -1;
        return c;        
    }
};
