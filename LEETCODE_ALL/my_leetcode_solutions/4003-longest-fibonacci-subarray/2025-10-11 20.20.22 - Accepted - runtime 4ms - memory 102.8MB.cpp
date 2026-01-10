class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int maxCount = 0,count=2;

        for(int i=2;i<nums.size();i++){
            if(nums[i-1]+nums[i-2] == nums[i])count++;
            else{
                count=2;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};