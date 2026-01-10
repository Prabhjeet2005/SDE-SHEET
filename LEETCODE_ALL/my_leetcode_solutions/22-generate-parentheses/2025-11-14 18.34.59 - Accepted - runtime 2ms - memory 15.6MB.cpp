class Solution {
    void get_all_strings(int open_count, int close_count, string curr,
                         vector<string>& final_ans, int n) {
        if (open_count + close_count == 2 * n) {
            final_ans.push_back(curr);
            return;
        }

        // Add open bracket
        if (open_count < n)
            get_all_strings(open_count + 1, close_count, curr + "(", final_ans,
                            n);

        if (close_count < open_count) {
            get_all_strings(open_count, close_count + 1, curr + ")", final_ans,
                            n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        int open_count = 0, close_count = 0;
        vector<string> final_ans;
        string curr = "";
        get_all_strings(open_count, close_count, curr, final_ans, n);
        return final_ans;
    }
};