class Solution {
public:
    vector<int> intersect(vector<int>& a,vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;
        int n=a.size();
        int m=b.size();
        vector<int> v;
        if(n==0)
            return v;
        while(i<n&&j<m){
            if(a[i]==b[j]){
                v.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j])
                j++;
            else
                i++;
        }
        return v;
    }
};
