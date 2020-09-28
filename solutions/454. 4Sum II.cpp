class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        long long cnt=0;
        
        vector<long long> arr;
        for(auto i:c){
            for(auto j:d){
                arr.push_back(i+j);
            }
        }
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                long long  key=a[i]+b[j];
                key*=-1;
                long long beg=0,last=arr.size()-1,ans=INT_MAX;
                    while(beg<=last){
                        long long  mid=(beg+last)/2;
                        if(arr[mid]==key){
                            ans=min(mid,ans);
                            last=mid-1;
                        }   
                        else if(arr[mid]>key){
                            last=mid-1;
                        }
                        else
                            beg=mid+1;
                    }
                    long long maxi;
                    beg=0,last=arr.size()-1,maxi=INT_MIN;
                    while(beg<=last){
                        long long mid=(beg+last)/2;
                        if(arr[mid]==key){
                            maxi=max(mid,maxi);
                            beg=mid+1;
                        }   
                        else if(arr[mid]>key){
                            last=mid-1;
                        }
                        else
                            beg=mid+1;
                    }
                    if(ans!=INT_MAX){
                        cnt+=maxi-ans+1;
                    }
            }
        }
        return cnt;
    }
};
