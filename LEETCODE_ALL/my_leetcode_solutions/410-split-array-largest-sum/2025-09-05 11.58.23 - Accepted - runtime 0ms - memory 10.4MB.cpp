class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end()),end = accumulate(nums.begin(),nums.end(),0);
        int answer = 0;
        if(nums.size()<k)return -1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int countSubarray=1,sumSubArr = 0;
            for(int i=0; i<nums.size(); i++){
                if(sumSubArr + nums[i] > mid){
                    sumSubArr = nums[i];
                    countSubarray++;
                }else{
                    sumSubArr += nums[i];
                }
            }

            if(countSubarray > k){
                start = mid+1;
            }else{
                answer = mid;
                end = mid-1;
            }
        }
        return answer;
    }
};