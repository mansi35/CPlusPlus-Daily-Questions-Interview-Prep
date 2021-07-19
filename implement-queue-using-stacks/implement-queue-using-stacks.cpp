class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> queueStack;
    stack<int> helperStack;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!queueStack.empty()) {
            helperStack.push(queueStack.top());
            queueStack.pop();
        }
        queueStack.push(x);
        while(!helperStack.empty()) {
            queueStack.push(helperStack.top());
            helperStack.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = queueStack.top();
        queueStack.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        return queueStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queueStack.empty();
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