class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string curr_str = "";
        long long curr_value = 0;
        long long last_operand = 0;
        solve(num, target, 0, ans, curr_str, curr_value, last_operand);

        return ans;
    }

private:
    void solve(string& nums, int target, int index, vector<string>& ans,
               string curr_str, long long curr_value, long long last_operand) {
        if (index >= nums.size()) {
            if (curr_value == target) {
                ans.push_back(curr_str);
            }
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[index] == '0') {
                break;
            }
            string curr_substr = nums.substr(index, i - index + 1);
            long long curr_digit = stoll(curr_substr);

            if (index == 0) {
                // Don't Add Operator at beginning
                solve(nums, target, i + 1, ans, curr_str + curr_substr,
                      curr_value + curr_digit, curr_digit);

            } else {
                // ADD
                solve(nums, target, i + 1, ans, curr_str + "+" + curr_substr,
                      curr_value + curr_digit, curr_digit);
                // Subtract
                solve(nums, target, i + 1, ans, curr_str + "-" + curr_substr,
                      curr_value - curr_digit, -curr_digit);

                // Multiply (UNDO & MULTIPLY)
                solve(nums, target, i + 1, ans, curr_str + "*" + curr_substr,
                      (curr_value - last_operand) + (last_operand * curr_digit),
                      curr_digit * last_operand);
            }
        }
    }
};