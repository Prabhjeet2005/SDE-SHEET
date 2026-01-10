class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        
        while(i<nums.size()){
            int j=0;
            while(j<nums.size()-1){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                }j++;
            }i++;
        }
    }
};