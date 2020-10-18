class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        if(n==0)
            return ans;
        if(n==1){
            ans.push_back(arr[0]*arr[0]);
            return ans;
​
        }
        int i=0;
        while(i<n&&arr[i]<0)
            i++;
        int j=i-1;
        while(i<n&&j>=0){
            int x=arr[i]*arr[i];
            int y=arr[j]*arr[j];
            if(x>y){
                ans.push_back(y);
                j--;
            }
            else{
                ans.push_back(x);
                i++;
            }
        }
        while(i<n){
            ans.push_back(arr[i]*arr[i]);
            i++;
        }
        while(j>=0){
            ans.push_back(arr[j]*arr[j]);
            j--;
        }
        return ans;
            
    }
};
