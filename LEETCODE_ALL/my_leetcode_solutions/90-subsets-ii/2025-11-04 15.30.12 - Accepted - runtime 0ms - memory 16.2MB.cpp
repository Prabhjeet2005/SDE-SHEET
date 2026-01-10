class Solution {
    void calculate_subsets(vector<int>nums,int index,vector<vector<int>>&final_ans, vector<int>&current_subset){
        if(index >= nums.size()){
            final_ans.push_back(current_subset);
            return;
        }

        // pick
        current_subset.push_back(nums[index]);
        calculate_subsets(nums,index+1,final_ans,current_subset);
        current_subset.pop_back();

        // skip duplicates
        while(index < nums.size()-1 && nums[index+1] == nums[index]){
            index++;
        }
        // not pick
        calculate_subsets(nums,index+1,final_ans,current_subset); 
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>final_ans;
        sort(nums.begin(),nums.end());
        vector<int>current_subset;
        calculate_subsets(nums,0,final_ans,current_subset);
        return final_ans;
    }
};