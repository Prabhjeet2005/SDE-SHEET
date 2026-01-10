class Solution {
public:
    string decodeString(string s) {
        int current_number = 0;
        string current_string = "";

        stack<int> count_stack;
        stack<string> string_stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                current_number = (current_number * 10 )+ (s[i]-'0');
                continue;
            }
            else if(s[i] == '['){
                count_stack.push(current_number);
                string_stack.push(current_string);
                current_number=0;current_string="";
            }
            else if(s[i]==']'){
                int repeat = count_stack.top();
                count_stack.pop();
                string prev_string = string_stack.top();
                string_stack.pop();
                string new_current_string = prev_string;

                for(int i=0; i<repeat;i++){
                    new_current_string+=current_string;
                }   
                current_string = new_current_string;
            }else{
                current_string += s[i];
            }
        }
        return current_string;
    }
};