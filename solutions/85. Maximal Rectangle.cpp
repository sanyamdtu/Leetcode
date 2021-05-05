            int b=-1;
            if(!s.empty())
                b=s.top();
            ans=max(ans,arr[a]*(n-b-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int n=a.size();
        if(n==0)
            return 0;
        int m=a[0].size();
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=a[i][j]-'0';
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)
                    arr[i][j]+=arr[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,func(arr[i]));
        }
        return ans;
    }
};
