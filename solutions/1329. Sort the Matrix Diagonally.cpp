class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            vector<int> t;
            int a=i,b=0;
            while(a<n&&b<m){
                
                t.push_back(arr[a++][b++]);
            }
            
            sort(t.begin(),t.end());
            a=i,b=0;
            int k=0;
            while(a<n&&b<m){
                v[a++][b++]=t[k++];
            }
        }
        for(int i=1;i<m;i++){
            vector<int> t;
            int a=0,b=i;
            while(a<n&&b<m){
                cout<<arr[a][b]<<" ";
                t.push_back(arr[a++][b++]);
            }
            cout<<endl;
            sort(t.begin(),t.end());
            a=0,b=i;
            int k=0;
            while(a<n&&b<m){
                v[a++][b++]=t[k++];
            }
        }
        return v;
    }
};
