class Solution {
    void solve_paranthesis(string current_string, int open_count,
                           int close_count, int n, vector<string>& final_ans) {

        if (open_count + close_count == 2 * n) {
            final_ans.push_back(current_string);
            return;
        }
        if (open_count < n) {
            solve_paranthesis(current_string + "(", open_count + 1, close_count,
                              n, final_ans);
        }
        if (close_count < open_count) {
            solve_paranthesis(current_string + ")", open_count, close_count + 1,
                              n, final_ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> final_ans;
        // maintain current_string,open_count,close_count
        solve_paranthesis("", 0, 0, n, final_ans);
        return final_ans;
    }
};