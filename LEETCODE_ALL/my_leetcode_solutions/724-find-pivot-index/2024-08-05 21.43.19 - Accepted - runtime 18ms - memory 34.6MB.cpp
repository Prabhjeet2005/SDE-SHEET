class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0, rsum = 0, i = 0;
        for(int i=0; i<nums.size(); i++){
            rsum+=nums[i];
        }
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