class Solution {
public:
    int removeElement(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==0)
            return 0;
        int i=0,j=n-1;
        while(i<=j){
            if(arr[i]==k){
                swap(arr[i],arr[j]);
                j--;
                n--;
            }
            else
                i++;
        }
        return n;
    }
};
