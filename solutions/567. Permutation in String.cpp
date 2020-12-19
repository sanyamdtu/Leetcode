class Solution {
public:
    bool checkInclusion(string a, string b) {
        int i=0;
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(auto i:a)
            arr[i-'a']++;
        int n=b.length();
        for(int j=0;j<n;j++){
            // cout<<b[j]<<" ";
            arr[b[j]-'a']--;
            if(j-i+1==a.length()){
                // cout<<i<<" "<<j<<endl;
                int f=0;
                for(int k=0;k<26;k++){
                    if(arr[k]!=0)
                        f=1;
                }
                if(f==0)
                    return true;
                arr[b[i++]-'a']++;
            }
        }
        return false;
    }
};
