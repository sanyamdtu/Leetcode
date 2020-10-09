class NumArray {
public:
    int prefix[100000];
    NumArray(vector<int>& arr) {
        int n=arr.size();
        if(n!=0){
            prefix[0]=arr[0];
            for(int i=1;i<n;i++){
                prefix[i]=prefix[i-1]+arr[i];
            }
        }
        
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return prefix[j];
        else return prefix[j]-prefix[i-1];
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
