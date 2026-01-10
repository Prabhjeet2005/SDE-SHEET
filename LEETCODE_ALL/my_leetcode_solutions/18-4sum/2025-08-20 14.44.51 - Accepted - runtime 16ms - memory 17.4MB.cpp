class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums.size() < 4)return ans;
        for(int i=0; i<nums.size()-3; i++){
            if(i!=0 && nums[i-1] == nums[i]){
                continue;
            }
            for(int j=i+1; j<nums.size()-2; j++){
                if(j != i+1 && nums[j-1]==nums[j]){
                    continue;
                }
                int start = j+1,end = nums.size()-1;
                while(start < end){
                    long long sumQuad = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];
                    if(sumQuad == target){
                        ans.push_back({nums[i] , nums[j] , nums[start] , nums[end]});
                        start++;
                        end--;
                        while(start < end && nums[start] == nums[start-1] )start++;
                        while(start < end && nums[end] == nums[end+1] )end--;
                    }else if(sumQuad < target){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};