class MinStack {
    stack<int> minStack;
    stack<int> mainStack;

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.empty())
            return;
        int poppedElement = mainStack.top();
        mainStack.pop();
        if (!minStack.empty() && minStack.top() == poppedElement) {
            minStack.pop();
        }
    }

    int top() {
        if (mainStack.empty())
            return -1;
        return mainStack.top();
    }

    int getMin() {
        if (minStack.empty())
            return -1;
        return minStack.top();
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