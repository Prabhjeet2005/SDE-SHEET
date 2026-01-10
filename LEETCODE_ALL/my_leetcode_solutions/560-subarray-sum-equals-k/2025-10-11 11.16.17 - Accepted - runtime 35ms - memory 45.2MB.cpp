class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSum;
        prefixSum[0]++;
        int count=0;
        int currentSum = 0;
        for(int i=0; i<nums.size();i++){
            currentSum += nums[i];
            if(prefixSum.count(currentSum - k)){
                count += prefixSum[currentSum - k];
            }
            prefixSum[currentSum]++;
        }
        return count;
    }
};