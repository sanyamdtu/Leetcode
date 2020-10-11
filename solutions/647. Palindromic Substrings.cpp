class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,n=s.length();
       for(int i=0;i<n;i++){
           ans++;
           int j=i-1,k=i+1;
           while(k<n&&j>=0){
               if(s[k]==s[j])
                   ans++;
               else
                   break;
               k++;
               j--;
           }
           j=i,k=i+1;
           while(k<n&&j>=0){
               if(s[k]==s[j])
                   ans++;
               else
                   break;
               k++;
               j--;
           }
           // j=i-1,k=i;
           // while(k<n&&j>=0){
           //     if(s[k]==s[j])
           //         ans++;
           //     else
           //         break;
           //     k++;
           //     j--;
           // }
       }
        return ans;
    }
};
