class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        map[nums[0]]=0;
        
        for(int i=1; i<nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                return {map[target-nums[i]],i};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};

    }
};