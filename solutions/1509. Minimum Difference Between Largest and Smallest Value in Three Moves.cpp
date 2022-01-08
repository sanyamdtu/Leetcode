class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
        if(n==1||n==2||n==3||n==4)
            return 0;
        sort(arr.begin(),arr.end());
        if(n==5)
        {
            return min(arr[1]-arr[0],min(arr[2]-arr[1],min(arr[3]-arr[2],(arr[4]-arr[3]))));
        }        
        return min(arr[n-1]-arr[3],min(arr[n-4]-arr[0],min(arr[n-2]-arr[2],arr[n-3]-arr[1])));
    }
};
