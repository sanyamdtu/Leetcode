class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod=1000*1000*1000+7;
        stack<pair<long long,long long>>s;
        long long n=arr.size();
        if(n==0)
            return 0;
        long long left[n];
        memset(left,0,sizeof(left));
        for(long long i=0;i<n;i++){
            while(!s.empty()&&s.top().first>=arr[i]){
                s.pop();
            }
            long long c=0;
            if(s.empty()){
                c=i;
            }
            else{
                c=i-s.top().second-1;
            }
            left[i]=c;
            s.push({arr[i],i});       
        }
        long long r[n];
        memset(r,0,sizeof(r));
        while(!s.empty())
        {
            s.pop();
        }
        for(long long i=n-1;i>=0;i--){
            while(!s.empty()&&s.top().first>arr[i]){
                s.pop();
            }
            long long c=0;
            if(s.empty()){
                c=n-1-i;
            }
            else{
                c=s.top().second-i-1;
            }
            r[i]=c;
            s.push({arr[i],i});       
        }
        long long ans=0;
        for(int i=0;i<n;i++){
