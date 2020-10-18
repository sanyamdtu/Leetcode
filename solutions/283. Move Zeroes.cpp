class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return ;
        int i=0;
        int j=0;
        while(j<n){
            while(j<n&&arr[j]==0)
                j++;
            while(i<n&&arr[i]!=0)
                i++;
            if(i>=n||j>=n)
                break;
            if(i>j){
                i=j+1;
                j=i+1;
            }
            else{
                swap(arr[i],arr[j]);
            }
        }
    }
};
