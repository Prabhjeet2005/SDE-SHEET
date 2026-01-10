class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int flag,c;
        for(int i=0;i<size(nums);i++){
            for(int j=i+1;j<size(nums);j++){
                c=nums[i]+nums[j];
                if(c==target){
                    return{i,j};
                    
                    }
            }
        }
        return{};
    }
};