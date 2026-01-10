class Solution {
    void find_target_sum(vector<int>& candidates, int index, int target,
                         int current_sum, vector<int>& current_sum_arr,
                         vector<vector<int>> &final_ans) {
        if (index >= candidates.size()) {
            return;
        }
        if (current_sum == target) {
            final_ans.push_back(current_sum_arr);
            return;
        } else if (current_sum > target) {
            return;
        }

        // pick
        // Pass index for Re-Pick
        current_sum_arr.push_back(candidates[index]);
        find_target_sum(candidates, index, target,
                        current_sum + candidates[index], current_sum_arr,
                        final_ans);
        current_sum_arr.pop_back();

        // not pick
        find_target_sum(candidates, index+1, target,
                        current_sum, current_sum_arr,
                        final_ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> final_ans;
        vector<int> current_sum_arr;
        int current_sum = 0;
        find_target_sum(candidates, 0, target, current_sum, current_sum_arr,
                        final_ans);

        return final_ans;
    }
};