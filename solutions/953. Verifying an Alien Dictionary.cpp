class Solution {
public:
    bool isAlienSorted(vector<string>& arr, string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i+1;
        }
        for(int i=1;i<arr.size();i++){
            string a=arr[i-1];
            string b=arr[i];
            int f=0;
            for(int j=0;j<min(a.length(),b.length());j++){
                cout<<m[a[j]]<<" "<<m[b[j]]<<" "<<a[j]<<endl;
                if(m[a[j]]>m[b[j]])
                    return false;
                else if(m[a[j]]<m[b[j]]){
                    f=1;
                    break;
                }
                    
            }
            if(a.length()>b.length()&&f==0)
                return false;
        }
        return true;
    }
};
