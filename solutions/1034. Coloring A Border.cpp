class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& arr,int r,int c,int k) {
        int n=arr.size();
        if(n==0)
            return arr;
        int m=arr[0].size();
        int ch=arr[r][c];
        arr[r][c]=-1;
        queue<pair<int,int>> q;
        q.push({r,c});
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            int f=0;
            for(int i=0;i<4;i++){
                int a=x+dx[i];
                int b=y+dy[i];
                if(a>=0&&b>=0&&a<n&&b<m){
                    if(arr[a][b]==ch){
                        arr[a][b]=-1;
                        q.push({a,b});
                    }
                    else if(arr[a][b]>0){
                        f=1;
                    }
                }
                else
                    f=1;
            }
            if(f==1){
                arr[x][y]=-2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==-1){
                    arr[i][j]=ch;
                }
                if(arr[i][j]==-2){
                    arr[i][j]=k;
                }
            }
        }
        return arr;
    }
};
