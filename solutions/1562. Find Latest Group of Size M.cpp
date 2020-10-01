class Solution {
public:
    int findLatestStep(vector<int>& a, int m) {
        int res = -1, n = a.size();
        if (n == m) return n;
        vector<int> length(n + 2);
        for(int i=0;i<n;i++){
            int curr=a[i];
            int l=length[curr-1],r=length[curr+1];
            length[curr-l]=length[curr+r]=l+r+1;
            if(l==m||r==m)
                res=i;                
        }
        return res;
    }
};
