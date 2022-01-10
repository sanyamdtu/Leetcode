class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(INT_MIN);
        for(auto i:nums)
            arr.push_back(i);
        arr.push_back(INT_MAX);
        int n=arr.size();
        int i=0;
        while(i<n-1&&arr[i]<=arr[i+1])
            i++;
        int j=n-1;
        while(j>0&&arr[j]>=arr[j-1])
            j--;
        if(i>=j)
            return 0;
        int l=i,r=j;
        cout<<l<<" "<<r<<endl;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=l;i<=r&&i>=0&&i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int fi=0,li=n-1;
        while(fi<n&&arr[fi]<=mini)
            fi++;
        while(li>=0&&arr[li]>=maxi)
            li--;
        if(fi>=li)
            return 0;
        return li-fi+1;
    }
};
