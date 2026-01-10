class Solution {
    void find_combination_candidates(vector<int>&candidates,int target,int index,int current_sum,vector<int>&current_candidates,vector<vector<int>>&final_ans){

        if(current_sum == target){
            final_ans.push_back(current_candidates);
            return;
        }else if(current_sum > target){
            return;
        }
        if(index >= candidates.size()){
            return;
        }

        // pick
        current_candidates.push_back(candidates[index]);
        find_combination_candidates(candidates,target,index+1,current_sum + candidates[index],current_candidates,final_ans);
        current_candidates.pop_back();

        // Skip Duplicates
        while(index < candidates.size()-1 && candidates[index] == candidates[index+1]){
            index++;
        }

        // not pick
        find_combination_candidates(candidates,target,index+1,current_sum,current_candidates,final_ans);


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>final_ans;
        vector<int>current_candidates;

        sort(candidates.begin(),candidates.end());

        find_combination_candidates(candidates,target,0,0,current_candidates,final_ans);

        return final_ans;
    }
};