class MinStack {
    // current element, min_element_so_far
    stack<pair<int,int>>stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push({val,val});
            return;
        }
        int min_element_till_now = min(val,stack.top().second);
        stack.push({val,min_element_till_now});
    }
    
    void pop() {
        if(!stack.empty())stack.pop();
    }
    
    int top() {
        if(stack.empty())return -1;
        return stack.top().first;
    }
    
    int getMin() {
        if(stack.empty())return -1;
        return stack.top().second;
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