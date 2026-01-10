class Solution {
public:
    bool check(vector<int>& nums) {

        int i=0,c=0;
        while(i<nums.size()-1){
            if(nums[i]>nums[i+1]){
                c++;
            }
            i++;
        }if(nums[nums.size()-1]>nums[0]){
                c++;
            }
        if(c<=1){
            return true;
        }else{
            return false;
        }
        
    }
};