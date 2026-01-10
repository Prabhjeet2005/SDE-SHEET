class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            unordered_map<int,int>freq;
            for(int j=i; j<nums.size(); j++){
                freq[nums[j]]++;
                if(freq[target] > ((j-i+1)/2)){
                    count++;
                }
            }
            
            
        }
        return count;
    }
};