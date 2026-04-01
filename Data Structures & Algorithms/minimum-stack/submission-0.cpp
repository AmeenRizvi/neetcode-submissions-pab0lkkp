class MinStack {
    stack<int>st;
    stack<int>stack2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minVal = INT_MAX;
        while(!st.empty())
        {
            minVal = min(minVal, st.top());
            stack2.push(st.top());
            st.pop();
        }

        while(!stack2.empty())
        {
            st.push(stack2.top());
            stack2.pop();
        }
        return minVal;
    }
};
