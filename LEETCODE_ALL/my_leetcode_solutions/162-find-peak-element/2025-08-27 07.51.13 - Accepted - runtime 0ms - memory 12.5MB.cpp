class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1,size = nums.size(),end = size-2;
        if(size == 1 || nums[0]>nums[1])return 0;
        if(nums[size-1]>nums[size-2])return size-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid-1]<nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[mid-1]<nums[mid] && nums[mid] < nums[mid+1]){
                start=mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
};