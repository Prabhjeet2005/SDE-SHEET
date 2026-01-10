class Solution {
    void find_first(vector<int>&arr,int start,int end,int &firstOcc,int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid]==target){
                firstOcc = mid;
                end = mid - 1;
            }else if(arr[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
    }
    void find_last(vector<int>&arr,int start,int end,int &lastOcc,int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid]==target){
                lastOcc = mid;
                start = mid + 1;
            }else if(arr[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0,end = size - 1,firstOcc = -1,lastOcc = -1;
        if(size == 0){
            return {-1,-1};
        }
        find_first(nums,start,end,firstOcc,target);
        find_last(nums,start,end,lastOcc,target);

        return {firstOcc,lastOcc};
    }
};