class Solution {
public:
    
    int shortestBridge(vector<vector<int>>& arr) {
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        
        int n=arr.size();
        int dis[n][n];
        memset(dis,0,sizeof(dis));
        queue<pair<int,int>> q;
        queue<pair<int,int>> qa;
        int f=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(arr[i][j]==1&&f==0){
                   q.push({i,j});
                   arr[i][j]=-1;
                   f=1;
                   while(!q.empty()){
                        auto a=q.front();
                        q.pop();
                        qa.push(a);
                        int x=a.first;
                        int y=a.second;
                        for(int i=0;i<4;i++){
                            int a=x+dx[i];
                            int b=y+dy[i];
                            if(a>=0&&b>=0&&a<n&&b<n&&arr[a][b]==1){
                                q.push({a,b});
                                arr[a][b]=-1;
                            }
                        }
                    }
               } 
           }
        }
        while(!qa.empty()){
            auto a =qa.front();
            qa.pop();
            int x=a.first;
            int y=a.second;
            for(int i=0;i<4;i++){
                int a=x+dx[i];
                int b=y+dy[i];
                if(a>=0&&b>=0&&a<n&&b<n){
                    if(arr[a][b]==1)
                        return dis[x][y];
                    if(arr[a][b]==0){
                        qa.push({a,b});
                        arr[a][b]=-1;
                        dis[a][b]=dis[x][y]+1;
                    }
                }
            }
        }
        return 0;
    }
};
