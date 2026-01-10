class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;

        for(int i=0; i<queries.size(); i++){
            long long left = queries[i][0];
            long long right = queries[i][1];
            long long k = queries[i][2];
            long long v = queries[i][3];
            while(left <= right){
                nums[left] = (nums[left] % mod * v % mod) % mod;
                left += k;
            }
        }
        int xorN = 0;
        for(int i=0; i<nums.size();i++){
            xorN ^= nums[i];
        }
        return xorN;
    }
};