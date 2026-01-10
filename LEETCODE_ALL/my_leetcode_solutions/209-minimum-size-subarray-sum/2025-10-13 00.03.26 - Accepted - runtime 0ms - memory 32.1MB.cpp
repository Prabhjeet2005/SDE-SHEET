class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0,right = 0,currentSum = 0,minLength = INT_MAX;

        while(right < nums.size()){
            currentSum += nums[right];
            if(currentSum < target){
                right++;continue;
            }
            while(left <= right && currentSum >= target){
                minLength = min(minLength,right-left+1);
                currentSum -= nums[left];
                left++;
            }
            right++;            
        }

        if(minLength == INT_MAX)return 0;
        return minLength;
    }
};