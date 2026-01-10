class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int currentSum = 0;
        int count = 0;

        for(int i=0; i<nums.size();i++){
            currentSum += nums[i];
            if(currentSum == k){
                count++;
            }
            if(map[currentSum - k]){
                count+= map[currentSum-k];
            }
            map[currentSum]++;
        }
        return count;
    }
};