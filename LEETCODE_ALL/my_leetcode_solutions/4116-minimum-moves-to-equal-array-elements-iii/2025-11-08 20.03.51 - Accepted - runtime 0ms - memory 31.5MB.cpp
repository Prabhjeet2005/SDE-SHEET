class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1)return 0;
       int ans = 0;
        int maxi = *max_element(nums.begin(),nums.end());

        for(auto& element:nums){
            ans += abs(element - maxi);
        }

        return ans;
    }
};