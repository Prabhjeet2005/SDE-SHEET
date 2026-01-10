class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        for(int i=0; i<nums.size();i++){
            freq[nums[i]]++;
        }

        int totalSum=0;
        for(auto &it:freq){
            if(it.second % k == 0){
                totalSum += (it.first * it.second);
            }
        }
        return totalSum;
    }
};