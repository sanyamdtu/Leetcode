class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i=0,j=0;
        int n=a.size(),m=b.size();
        vector<vector<int>> v;
        while(i<n&&j<m){
            vector<int >s;
            if(a[i][1]<b[j][0]){
                i++;
            }
            else if(a[i][0]>b[j][1]){
                j++;
            }
            else{
                int x=max(a[i][0],b[j][0]);
                int y=min(a[i][1],b[j][1]);
                s.push_back(x);
                s.push_back(y);
                v.push_back(s);
                if(y==b[j][1])
                    j++;
                if(y==a[i][1])
                    i++;
            }
        }
        return v;
    }
};
