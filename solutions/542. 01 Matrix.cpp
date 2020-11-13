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
                if(x>=0&&y>=0&&x<n&&y<m&&dist[x][y]==INT_MAX){
                // if(dist[a.first][a.second]+1<dist[x][y]){
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
