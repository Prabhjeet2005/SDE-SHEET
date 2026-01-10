class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorArr = 0;

        for(int i=0; i<nums.size(); i++){
            xorArr ^= nums[i];
        }

        return xorArr;
    }
};