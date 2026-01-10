class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 4 5 6 7 0 1 2
        int start = 0,end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid]==target)return mid;
            else if(nums[mid] <= nums[end]){
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }else{
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
        }

        return -1;
    }
};