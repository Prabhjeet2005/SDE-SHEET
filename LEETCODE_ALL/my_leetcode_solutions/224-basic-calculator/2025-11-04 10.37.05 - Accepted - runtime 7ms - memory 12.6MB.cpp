class Solution {
public:
    int calculate(string s) {
        stack<long long> result_sign_stack;
        long long current_result = 0, current_number = 0, current_sign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;

            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                // Number or multi-digit number
                current_number = current_number * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                current_result += (current_sign * current_number);
                result_sign_stack.push(current_result);
                result_sign_stack.push(current_sign);
                current_result = 0, current_number = 0, current_sign = 1;
            } else if (s[i] == ')') {
                current_result += current_sign * current_number;
                current_number = 0;
                int prev_sign = result_sign_stack.top();
                result_sign_stack.pop();
                long long prev_result = result_sign_stack.top();
                result_sign_stack.pop();

                current_result = prev_result + (prev_sign * current_result);
            } else {
                // Sign
                current_result += (current_sign * current_number);
                current_number = 0;
                if (s[i] == '+') {
                    current_sign = 1;
                } else if (s[i] == '-') {
                    current_sign = -1;
                }
            }
        }

        current_result = current_result + (current_sign * current_number);

        return current_result;
    }
};