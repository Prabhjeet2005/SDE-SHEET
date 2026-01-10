class Solution {
    void solve_permutations(vector<int>& nums,
                            vector<vector<int>>& final_permutations,
                            vector<bool>& visited,
                            vector<int>& current_permutations) {

        if (current_permutations.size() == nums.size()) {
            final_permutations.push_back(current_permutations);
            return;
        }

        // Do For Each Slot
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                // Duplicate Logic ==> Take the first element of duplicates
                // !visited[i-1] -> if earlier is not picked then this means
                // this is a duplicate path
                continue;
            }
            if (visited[i]) // Already Visited Slot
                continue;
            current_permutations.push_back(nums[i]);
            visited[i] = true;
            solve_permutations(nums, final_permutations, visited,
                               current_permutations);
            current_permutations.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> final_permutations;
        vector<bool> visited(nums.size(), 0);
        vector<int> current_permutations;

        sort(nums.begin(), nums.end());
        solve_permutations(nums, final_permutations, visited,
                           current_permutations);

        return final_permutations;
    }
};