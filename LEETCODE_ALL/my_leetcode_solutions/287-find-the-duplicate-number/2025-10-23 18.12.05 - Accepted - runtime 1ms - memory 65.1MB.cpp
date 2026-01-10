class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(fast < nums.size()){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                slow = nums[0];
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                break;
            }
        }
        return slow;
    }
};