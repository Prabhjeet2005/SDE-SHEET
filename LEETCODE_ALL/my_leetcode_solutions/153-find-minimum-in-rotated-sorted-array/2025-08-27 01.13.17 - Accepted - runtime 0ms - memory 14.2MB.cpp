class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1,minElement = INT_MAX;
        while(start <= end){
            int mid = start+(end-start)/2;
            if(nums[start]<=nums[mid]){
                minElement = min(minElement,nums[start]);
                start = mid+1;
            }else{
                minElement = min(minElement,nums[mid]);
                end = mid-1;
            }
        }
        return minElement;
    }
};