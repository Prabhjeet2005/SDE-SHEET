class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        for(int i=0; i<nums.size();i++){
            if(i==0){
                prefix[0] = nums[0];
                continue;
            }
            prefix[i] = prefix[i-1] * nums[i];
        }
        for(int i=nums.size()-1; i>=0;i--){
            if(i==nums.size()-1){
                suffix[nums.size()-1] = nums[nums.size()-1];
                continue;
            }
            suffix[i] = suffix[i+1] * nums[i];
        }
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i-1 < 0){
                ans[i]=suffix[i+1];
                continue;
            }
            if(i+1 >= nums.size()){
                ans[i]=prefix[i-1];
                continue;
            }
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};