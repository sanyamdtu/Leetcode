class FreqStack {
public:
    unordered_map<int,stack<int>> m;
    unordered_map<int,int> p;
    int maxi;
    FreqStack() {
        maxi=-1;
        m.clear();
        p.clear();
    }
    void push(int val) {
        p[val]++;
        m[p[val]].push(val);
        maxi=max(p[val],maxi);
    }
    int pop() {
        int a=m[maxi].top();
        p[a]--;
        m[maxi].pop();
        if(m[maxi].empty())
            maxi--;
        return a;
    }
};
​
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
