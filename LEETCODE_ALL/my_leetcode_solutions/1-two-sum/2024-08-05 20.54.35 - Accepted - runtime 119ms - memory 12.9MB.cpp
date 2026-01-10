class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int s=0,e=nums.size()-1;
        while(s<e){
            if(nums[s]+nums[e]==target){
                return{s,e};
                
            }e--;
            if(e==s){
                s++;
                e=nums.size()-1;
            }
            
        }
        return {};
    }
};