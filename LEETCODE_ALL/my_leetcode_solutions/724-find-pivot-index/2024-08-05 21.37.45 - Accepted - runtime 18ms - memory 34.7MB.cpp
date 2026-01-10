class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0, rsum = 0, i = 0;
        rsum = accumulate(nums.begin(), nums.end(), 0);
        while (i < nums.size()) {
            if (lsum == (rsum-nums[i])) {
                return i;
            }else{
                lsum+=nums[i];
                rsum-=nums[i];
            }
            i++;
        }
        return -1;
    }
};