class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentOne = 0;
        int maxOne = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                currentOne = 0;
                continue;
            }
            currentOne++;
            maxOne = max(maxOne,currentOne);
        }
        return maxOne;
    }
};