​
class MyQueue {
    stack<int> s1,s2;
public:
    
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a=s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return a;
