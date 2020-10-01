class Solution {
public:
    int func(vector<int> arr,int k,int s,int e){
        if(s>e)
            return -1;
        if(s==e)
            return (arr[s]==k)?s:-1;
        int mid=(s+e)/2;
        if(arr[mid]==k)
            return mid;
        if(arr[mid]>=arr[s]){
            if(arr[mid]>k&&arr[s]<=k)
                return func(arr,k,s,mid-1);
            else
                return func(arr,k,mid+1,e);
        }
        else{
            if(arr[mid+1]<=k&&arr[e]>=k)
                return func(arr,k,mid+1,e);
            else
                return func(arr,k,s,mid-1);
        }
    }
    int search(vector<int>& arr, int k) {
        return (func(arr,k,0,arr.size()-1));
    }
};
