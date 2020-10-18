class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> v;
        int i=0,j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size();
        int m=b.size();
        if(n==0||m==0)
            return v;
        if(n==1&&m==1){
            if(a[0]==b[0])
                v.push_back(a[0]);
            return v;
        }
            
        while(i<n&&j<m){
            if(a[i]==b[j])
            {
                if(v.empty()||v.back()!=a[i])
                v.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else
                i++;
        }
        return v;
    }
};
