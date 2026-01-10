class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0,element1 = INT_MIN,count2 = 0,element2 = INT_MIN;

        for(int i=0; i<nums.size();i++){
            if(count1==0 && element2 != nums[i]){
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2==0 && element1 != nums[i]){
                count2 = 1;
                element2 = nums[i];
            }else if(element1 == nums[i]){
                count1++;
            }else if(element2 == nums[i]){
                count2++;
            }else{
                count1--;count2--;
            }
        }
        vector<int>ans;
        count1=0,count2=0;
        for(auto &it:nums){
            if(element1 == it)count1++;
            if(element2 == it)count2++;
        }
        if(count1 > floor(nums.size()/3))ans.push_back(element1);
        if(count2 > floor(nums.size()/3))ans.push_back(element2);
        return ans;
    }
};