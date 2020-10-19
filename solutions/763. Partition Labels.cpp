class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v; 
        int arr[26]={-1};
        int n=s.length();
        if(n==0)
            return v;
        int c=1;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']=max(i,arr[s[i]-'a']);
        }
        int i=1,j=arr[s[0]-'a'];
        while(i<n){
            if(i==j+1){
                v.push_back(c);
                c=0;
            }
            c++;
            j=max(arr[s[i]-'a'],j);
            i++;
        }
        v.push_back(c);
        return v;
    }
};
​
​
