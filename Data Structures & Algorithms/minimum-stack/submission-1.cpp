class MinStack {
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int minVal = minStack.empty() ? val : min(minStack.top(), val);
        minStack.push(minVal);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
