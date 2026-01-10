class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int final_ans = 0;
        stack<string> stack;
        stack.push(tokens[0]);
        for (int i = 1; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" ||
                tokens[i] == "*") {
                int second_number = stoi(stack.top());
                stack.pop();
                int first_number = stoi(stack.top());
                stack.pop();
                if (tokens[i] == "+") {
                    stack.push(to_string(first_number + second_number));
                }
                else if (tokens[i] == "-") {
                    stack.push(to_string(first_number - second_number));
                }
                else if (tokens[i] == "*") {
                    stack.push(to_string(first_number * second_number));
                }
                else if (tokens[i] == "/") {
                    stack.push(to_string(first_number / second_number));
                }
            }else{
                stack.push(tokens[i]);
            }
        }

        if(!stack.empty())final_ans = stoi(stack.top());
        return final_ans;
    }
};