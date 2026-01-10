class Solution {
    void calculate_permutations(vector<int>&nums,vector<vector<int>>&final_permutations,vector<int>&current_permutations,vector<bool>&visited){
        if(current_permutations.size() == nums.size()){
            final_permutations.push_back(current_permutations);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            // Because Every slot must have all numbers at least once
            if(visited[i])continue; // which slots filled
            current_permutations.push_back(nums[i]);
            visited[i] = true;
            calculate_permutations(nums,final_permutations,current_permutations,visited);
            current_permutations.pop_back();
            visited[i] = false;

        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>final_permutations;
        vector<int>current_permutations;
        vector<bool>visited(nums.size(),0);

        calculate_permutations(nums,final_permutations,current_permutations,visited);

        return final_permutations;


    }
};