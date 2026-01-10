class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>ans(size);

        // Store Prefix in ans
        for(int i=0;i<size;i++){
            if(i==0){
                ans[i] = nums[i];
                continue;
            }
            ans[i] = ans[i-1]*nums[i];
        }

        int suffix = 1;
        for(int i=size-1;i>=0;i--){
            if(i==size-1){
                ans[i] = ans[i-1];
                suffix = nums[i];
                continue;
            }
            if(i==0){
                ans[i]=suffix;
                break;
            }
            ans[i] = ans[i-1]*suffix;
            suffix = suffix * nums[i];
        }
        return ans;


    }
};