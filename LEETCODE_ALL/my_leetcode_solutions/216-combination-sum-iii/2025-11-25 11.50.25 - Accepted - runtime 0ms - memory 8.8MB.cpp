class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> final_ans;
        vector<int> curr_combo;
        long long curr_sum = 0;
        solve(k, n, final_ans, curr_combo, curr_sum, 1);
        return final_ans;
    }

private:
    // k -> size, n -> target
    void solve(int k_size, int target_sum, vector<vector<int>>& final_ans,
               vector<int>& curr_combo, long long& curr_sum, int start_index) {
        if (curr_combo.size() >= k_size && curr_sum == target_sum) {
            final_ans.push_back(curr_combo);
            return;
        } else if (curr_combo.size() >= k_size && curr_sum != target_sum) {
            return;
        }

        for (int j = start_index; j <= 9; j++) {
            curr_sum += j;
            curr_combo.push_back(j);
            solve(k_size, target_sum, final_ans, curr_combo, curr_sum, j + 1);
            // Backtrack
            curr_sum -= j;
            curr_combo.pop_back();
        }
    }
};