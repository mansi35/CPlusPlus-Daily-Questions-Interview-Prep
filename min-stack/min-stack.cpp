class MinStack {
public:
    /** initialize your data structure here. */
    multiset<int> s;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        s.insert(val);
        st.push(val);
    }
    
    void pop() {
        s.erase(s.lower_bound(st.top()));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *(s.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */