class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int target = 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(i!=0 && nums[i] == nums[i-1])continue;
            int ptr1 = i+1, ptr2 = nums.size()-1;
            while(ptr1 < ptr2){
                if(nums[i]+nums[ptr1] + nums[ptr2] == target){
                    ans.push_back({nums[i],nums[ptr1],nums[ptr2]});
                    ptr1++;ptr2--;
                    while(ptr1 < ptr2 && nums[ptr1] == nums[ptr1-1])ptr1++;
                    while(ptr1 < ptr2 && nums[ptr2] == nums[ptr2+1])ptr2--;
                }
                else if(nums[i]+nums[ptr1] + nums[ptr2]< target){
                    ptr1++;
                }
                else if(nums[i]+nums[ptr1] + nums[ptr2] > target){
                    ptr2--;
                }
            }
        }
        return ans;
    }
};