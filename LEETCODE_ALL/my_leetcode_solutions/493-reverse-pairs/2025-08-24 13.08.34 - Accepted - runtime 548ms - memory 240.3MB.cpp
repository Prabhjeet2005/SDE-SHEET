class Solution {
    void merge(vector<int>&nums,int start,int mid,int end){
        vector<int>temp;
        int left = start,right = mid +1;
        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        while(right <= end){
            temp.push_back(nums[right++]);
        }

        for(int i=start; i<= end; i++){
            nums[i] = temp[i-start];
        }
    }
    void count_pairs(vector<int>&nums,int start,int mid,int end,int & count){
        int left = start;
        int right = mid+1;

        while(left <= mid ){
            while(right <= end && nums[left] > (long long)2*nums[right])right++;
            count+= (right - (mid+1));
            left++;
        }
    }
    void mergeSort(vector<int>&nums,int start,int end,int &count){
        if(start >=end)return;
        int mid = start + (end - start)/2;
        mergeSort(nums,start,mid,count);
        mergeSort(nums,mid+1,end,count);
        count_pairs(nums,start,mid,end,count);
        merge(nums,start,mid,end);
    }
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums,0,nums.size()-1,count);
        return count;
    }
};