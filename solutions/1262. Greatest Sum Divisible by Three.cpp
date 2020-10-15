class Solution {
public:
    int maxSumDivThree(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        if(n==0)
            return 0;
        vector<int> v[3];
        for(int i=0;i<n;i++){
            v[arr[i]%3].push_back(arr[i]);
            sum+=arr[i];
        }
        for(int i=0;i<3;i++)
            sort(v[i].begin(),v[i].end());
        if(sum%3==1){
            int m=sum;
            if(!v[1].empty())
                m=v[1][0];
            if(v[2].size()>=2)
                m=min(m,v[2][0]+v[2][1]);
            return sum-m;
        }
        if(sum%3==2){
            int m=sum;
            if(!v[2].empty())
                m=v[2][0];
            if(v[1].size()>=2)
                m=min(m,v[1][0]+v[1][1]);
            return sum-m;
        }
        return sum;
    }
};
