class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long sum = 0;
        if(nums.size() == 1){return 0;}

        long long maxi = *max_element(nums.begin(),nums.end());
        long long mini = *min_element(nums.begin(),nums.end());

        sum = (maxi - mini) * k;

        return sum;
    }
};