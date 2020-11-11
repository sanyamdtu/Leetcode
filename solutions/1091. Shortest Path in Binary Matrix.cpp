class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n=arr.size();
        int dist[n][n];
        queue<pair<int,int>> q;
        if(arr[0][0]==0)
            q.push({0,0});
        
        int dx[]={1,1,-1,-1,0,0,1,-1};
        int dy[]={1,-1,1,-1,1,-1,0,0};
        // int dist[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=100000;
        dist[0][0]=1;
        while(!q.empty()){
            // cout<<"pop";
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            for(int i=0;i<8;i++){
                int c=x+dx[i];
                int d=dy[i]+y;
                
                if(c>=0&&d>=0&&c<n&&d<n&&arr[c][d]==0){
                    // cout<<c<<" "<<d<<endl;;
                    if(dist[c][d]>dist[x][y]+1){
                        
                        q.push({c,d});
                        dist[c][d]=dist[x][y]+1;
                    }
                    
                }
            }
        }
        int a=dist[n-1][n-1];
        return (a==100000)?-1:a;
    }
};
