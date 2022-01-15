class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        int len=1;
        int a=0;
        int c=0,d=0;
        int idx=1;
        while(idx<n&&arr[idx]==arr[a]){
            c++;
            idx++;
        }
        if(idx==n)
            return n;
        int b=idx;
        c=0;
        d++;
        int ans=idx+1;
        for(int i=idx+1;i<n;i++){
            if(arr[i]==arr[a]){
                d=0;
                c++;
            }
            else if(arr[i]==arr[b]){
                c=0;
                d++;
            }
            else{
                if(d==0)
                {
                    b=i;
                    d=1;
                    a=i-c;
                    c=0;
                }
                else{
                    a=i;
                    c=1;
                    b=i-d;
                    d=0;
                }
            }
            // cout<<a<<" "<<b<<" "<<i<<" "<<arr[i]<<" "<<ans<<endl;
            ans=max(ans,i+1-min(a,b));
        }
        return ans;    
    }
};
