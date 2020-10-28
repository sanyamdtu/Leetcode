class Solution {
public:
    bool isValid(string arr) {
        int n=arr.length();
        stack<char> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else{
                if(arr[i]=='b'){
                    if(s.top()=='a'){
                        s.pop();
                        s.push('.');
                    }
                    else
                        s.push('b');
                }
                else if(arr[i]=='c'){
                    if(s.top()=='.')
                        s.pop();
                    else
                        s.push('c');
                }
                else
                    s.push(arr[i]);
            }
        }
        while(!s.empty()){
            if(s.top()=='c'){
                s.pop();
                if(!s.empty()&&s.top()=='.'){
                    s.pop();
                }
                else{
                    s.push('c');
                    break;
                }
                    
            }
            else
                break;
        }
        
        return s.empty();
    }
};
