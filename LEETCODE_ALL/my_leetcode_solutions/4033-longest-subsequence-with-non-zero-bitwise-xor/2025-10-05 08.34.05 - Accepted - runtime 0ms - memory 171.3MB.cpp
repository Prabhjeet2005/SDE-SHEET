class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if(nums.size() < 1){
            return 0;
        }
        int totalXOR = 0,totalOR=0;
        for(int i=0; i<nums.size();i++){
            totalXOR ^= nums[i];
            totalOR |= nums[i];
        }
        if(totalXOR != 0){
            return nums.size();
        }
        if(totalOR == 0)return 0;
        return nums.size()-1;
    }
};