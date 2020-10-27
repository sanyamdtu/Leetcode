class CustomStack {
public:
    vector<int> arr;
    vector<int> s;
    int maxi;
    CustomStack(int maxSize) {
        maxi=maxSize;
    }
    
    void push(int x) {
        if(s.size()!=maxi){
            s.push_back(x);
            arr.push_back(0);
        }
     
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int a=s.back();
        s.pop_back();
        int i=arr.size()-1;
        if(i>0) arr[i-1]+=arr[i];
        int b=arr[i];      
        arr.pop_back();
        return a+b;
    }
    
    void increment(int k, int val) {
        if(!arr.empty()){
         k=min(k-1,(int)arr.size()-1);
            arr[k]+=val;   
        }
    }
};
​
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
