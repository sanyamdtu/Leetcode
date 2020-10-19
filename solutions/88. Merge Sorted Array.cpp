class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        vector<int> v;
        int i=0,j=0;
        while(i<n&&j<m){
            if(a[i]<b[j]){
                v.push_back(a[i]);
                i++;
            }
            else
            {
                v.push_back(b[j]);
                j++;
            }
        }
        while(i<n)
        {
            v.push_back(a[i]);
            i++;
        }
        while(j<m){
            v.push_back(b[j]);
            j++;
        }
        a=v;
        return ;
    }
};
