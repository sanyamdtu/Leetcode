class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int key) {
        
        int n=arr.size(),m;
        if(n==0)
            m=0;
        else
            m=arr[0].size();
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(arr[i][j]<key)
                i++;
            else if(arr[i][j]==key) 
                return true;
            else
                j--;
                
        }
        return false;
    }
};
