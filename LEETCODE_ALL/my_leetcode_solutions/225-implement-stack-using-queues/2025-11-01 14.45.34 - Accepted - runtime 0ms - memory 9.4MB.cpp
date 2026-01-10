class MyStack {
    queue<int>queue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int element_to_push = x;
        if(queue.empty()){
            queue.push(element_to_push);
            return;
        }
        int size = queue.size();
        queue.push(element_to_push);
        for(int i=0;i<size;i++){
            int front_element = queue.front();
            queue.pop();
            queue.push(front_element);
        }
    }
    
    int pop() {
        if(queue.empty())return -1;
        int popped_element = queue.front();
        queue.pop();
        return popped_element;
    }
    
    int top() {
        if(queue.empty())return -1;
        int front_element = queue.front();
        return front_element;
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */