class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>set(nums.begin(),nums.end());

        for(int i=k; i<=nums.size()*k + k; i+=k){
            if(!set.count(i)){
                return i;
            }
        }
        return k;
        
    }
};