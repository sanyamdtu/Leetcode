class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int l, int m) {
        int n=arr.size();
        int ans=-1;
        int currl=0,maxi=-1,currm=0;
        for(int i=0,j=0,k=0;j<n;j++){
            currl+=arr[j];
            if(j-i+1==l){
                if(i-k==m){
                    maxi=max(maxi,currm);
                    ans=max(currl+maxi,ans);
                    
                    currm-=arr[k];
                    k++;
                }
                currl-=arr[i];
                currm+=arr[i];
                i++;
            }
        }
        currl=0,maxi=-1,currm=0;
        for(int i=0,j=0,k=0;j<n;j++){
            currm+=arr[j];
            if(j-i+1==m){
                if(i-k==l){
                    // cout<<currm<<" "<<maxi;
                    maxi=max(maxi,currl);
                    ans=max(currm+maxi,ans);
                    currl-=arr[k];
                    k++;
                }
                currm-=arr[i];
                currl+=arr[i];
                i++;
            }
        }
        return ans;
        
    }
};
