class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint = -1;

        for(int i = nums.size()-1; i>0;i--){
            if(nums[i-1] < nums[i]){
                breakPoint = i-1;
                break;
            }
        }

        if(breakPoint == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=nums.size()-1; i>breakPoint; i--){
            if(nums[breakPoint] < nums[i]){
                swap(nums[breakPoint],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+breakPoint+1,nums.end());

    }
};