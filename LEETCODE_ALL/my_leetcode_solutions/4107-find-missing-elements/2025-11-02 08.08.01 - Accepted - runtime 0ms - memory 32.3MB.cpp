class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = nums[0];
        int end = nums[nums.size()-1];
        int current = 1;
        vector<int>ans;
        for(int i=start+1;i<end;i++){
            auto found = find(nums.begin(),nums.end(),i);
            if(found == nums.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};