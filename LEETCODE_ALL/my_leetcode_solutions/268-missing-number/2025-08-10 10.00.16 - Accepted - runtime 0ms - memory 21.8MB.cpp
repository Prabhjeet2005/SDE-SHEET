class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNumber = 0;
        int xorN = 0;
        int xorArr = 0;

        for(int i=0; i<nums.size(); i++){
            xorArr ^= nums[i];
        }

        for(int i=0; i<= nums.size(); i++){
            xorN ^= i;
        }

        missingNumber = xorN ^ xorArr;
        return missingNumber;
    }
};