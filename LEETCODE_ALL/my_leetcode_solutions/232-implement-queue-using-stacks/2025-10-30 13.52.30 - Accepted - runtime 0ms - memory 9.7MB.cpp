class MyQueue {
    stack<int>input_stack;
    stack<int>output_stack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input_stack.push(x);
    }
    
    int pop() {
        if(output_stack.empty()){
            // Repeatidly pop from input and store in output to show FIFO
            while(!input_stack.empty()){
                int top_input_stack = input_stack.top();
                input_stack.pop();
                output_stack.push(top_input_stack);
            }
            int popped_element = output_stack.top();
            output_stack.pop();
            return popped_element;
        }else{  
            int top_output_stack = output_stack.top();
            output_stack.pop();
            return top_output_stack;
        }
    }
    
    int peek() {
        if(output_stack.empty()){
            // Repeatidly pop from input and store in output to show FIFO
            while(!input_stack.empty()){
                int top_input_stack = input_stack.top();
                input_stack.pop();
                output_stack.push(top_input_stack);
            }
            
            return output_stack.top();
        }else{  
            int top_output_stack = output_stack.top();
            return top_output_stack;
        }
    }
    
    bool empty() {
        if(output_stack.empty() && input_stack.empty())return true;
        return false;
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