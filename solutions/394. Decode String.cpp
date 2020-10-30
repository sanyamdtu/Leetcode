class Solution {
public:
    string decodeString(string arr) {
        int n=arr.length();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(isdigit(arr[i])){
                int num=0;
                while(isdigit(arr[i])){
                    num=num*10+arr[i]-'0';
                    i++;
                }
                s.push(num+'0');
                s.push(arr[i]);
            }
            else{
                
                if(arr[i]==']'){
                    string curr="";
                    while(s.top()!='['){
                        curr+=s.top();
                        s.pop();
                    }
                    reverse(curr.begin(),curr.end());
