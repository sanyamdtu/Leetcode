class Solution {
public:
    int compress(vector<char>& arr) {
        int n=arr.size();
        if(n<=1)
            return n;
        char ch=arr[0];
        int f=1;
        int i=0;
        for(int j=1;j<n;j++){
            if(arr[j]==ch)
                f++;
            else{
                arr[i++]=ch;
                if(f!=1){
                    for(auto k:to_string(f)){
                        arr[i++]=k;
                    }
                }
                f=1;
                ch=arr[j];
            }
        }
        arr[i++]=ch;
        if(f!=1){
            for(auto k:to_string(f)){
                arr[i++]=k;
            }
        }
        for(int k=i;k<n;k++)
            arr.pop_back();
        return arr.size();
    }};
