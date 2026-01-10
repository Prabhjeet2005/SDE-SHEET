class Solution {
    void calculate_subsets(int index, vector<int>& nums,
                           vector<vector<int>>& final_ans,
                           vector<int> &current_subset) {
        // Base Case
        if (index >= nums.size()) {
            final_ans.push_back(current_subset);
            return;
        }

        // not pick
        calculate_subsets(index + 1,nums, final_ans, current_subset);
        // pick
        current_subset.push_back(nums[index]);
        calculate_subsets(index + 1,nums, final_ans,current_subset);
        current_subset.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final_ans;
        vector<int> current_subset;
        calculate_subsets(0, nums, final_ans, current_subset);

        return final_ans;
    }
};