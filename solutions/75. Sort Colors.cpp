class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0,k=n-1;
        while(j<=k){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
            }
            else if(arr[j]==2)
            {
                swap(arr[k],arr[j]);
                k-- ;
            }
            else{
                swap(arr[j],arr[j]);
                j++;
            } 
            if(i>j)
                j++;
            // for(int i=0;i<n;i++)
            //     cout<<arr[i]<<" ";
            // cout<<endl;
        }
        
    }
};
