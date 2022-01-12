class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n=arr.size();
        int vis[n];
        vis[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            vis[i]=vis[i+1]+arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        int pop[n];
        memset(pop,0,sizeof(pop));
        for(int i=0;i<n;i++){
            if(arr[i]>=0)
                pop[i]=1;
        }
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<0){
                if(c+arr[i]>=0){
                    pop[i]=1;
                    c+=arr[i];
                }
            }
            else
                c+=arr[i];
        }
        int r=1;
        for(int i=0;i<n;i++){
            if(pop[i]==1){
                // cout<<arr[i]<<" ";
                ans+=arr[i]*r;
                r++;
            }
        }
        return ans;
    }
};
