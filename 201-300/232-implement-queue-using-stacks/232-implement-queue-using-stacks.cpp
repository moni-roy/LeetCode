class MyQueue {
private:
    stack<int> stk1, stk2;
public:
    MyQueue() {
        // do intialization if necessary
    }
    
    void push(int x) {
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(x);
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }
    
    int pop() {
        int res = stk2.top();
        stk2.pop();
        return res;
    }
    
    int peek() {
        return stk2.top();
    }
    
    bool empty() {
        return stk2.empty();      
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */