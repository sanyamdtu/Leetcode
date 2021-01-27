class Solution {
public:
    void rev(vector<int>& arr,int j){
        for(int i=0;i<j;i++,j--)
        {
            swap(arr[i],arr[j]);
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        while(n>0){
            int maxi=-1;
            for(int i=0;i<n;i++){
                if(maxi==-1)
                    maxi=i;
                else if(arr[maxi]<arr[i])
                    maxi=i;
            }
            if(maxi!=n-1)
            {
                rev(arr,maxi);
                ans.push_back(maxi+1);
                ans.push_back(n);
                rev(arr,n-1);
            }   
            n--;
        }
        return ans;
    }
};
