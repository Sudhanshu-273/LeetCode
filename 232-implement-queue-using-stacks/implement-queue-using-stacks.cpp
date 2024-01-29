class MyQueue {
public:

    stack<int> pushStack, popStack;

    MyQueue() {
        
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        if(!popStack.empty()) {
            int val = popStack.top();
            popStack.pop();
            return val;
        } else {
            while(!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            int val = popStack.top();
            popStack.pop();
            return val;
        }
    }
    
    int peek() {
        if(!popStack.empty()) {
            return popStack.top();
        } else {
            while(!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            return popStack.top();
        }
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
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