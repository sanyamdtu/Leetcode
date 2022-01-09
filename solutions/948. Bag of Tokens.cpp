class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int p) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0,res=0;
        for(int i=0,j=n-1;i<=j;){
            if(p>=arr[i]){
                ans++;
                p-=arr[i];
                i++;
            }
            else{
                if(i==j)
                    break;
                if(p+arr[j]>=arr[i]){
                    p+=arr[j]-arr[i];
                    j--;
                    ans--;
                    if(ans<0)
                        break;
                    ans++;
                    i++;
                }
                else{
                    break;
                }
            }
            res=max(ans,res);
        }
        return res;
    }
};
