class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long count = 0;
        long long balance = 0;
        long long valid_here = 0;
        unordered_map<long long,int>freq;

        freq[0] = 1;

        for(auto &element:nums){
            if(element == target){
                // here valid
                balance++;
                valid_here += freq[balance-1];
            }else{
                // not valid
                balance--;
                valid_here -= freq[balance];
            }
            count+=valid_here;
            freq[balance]++;
            
        }
        return count;
    }
};