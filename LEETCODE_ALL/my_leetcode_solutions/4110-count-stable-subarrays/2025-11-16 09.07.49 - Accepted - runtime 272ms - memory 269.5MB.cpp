class Solution {
    long long countSubarray(long long n){
        return n*(n+1)/2;
    }
public:
    vector<long long> countStableSubarrays(vector<int>& nums,
                                           vector<vector<int>>& queries) {
        vector<long long> ans;

        vector<int> last(nums.size());

        last[nums.size() - 1] = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                last[i] = last[i + 1];
            else
                last[i] = i;
        }

        int b_size = (int)sqrt(nums.size()) + 1;

        vector<int> hop(nums.size());
        vector<long long> sum(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            int next_bs = last[i] + 1;

            if (next_bs < nums.size() && (i / b_size) == (next_bs / b_size)) {
                hop[i] = hop[next_bs];
                long long c_bl = last[i] - i + 1;
                sum[i] = countSubarray(c_bl) + sum[next_bs];
            } else {
                hop[i] = next_bs;
                long long c_bl = last[i] - i + 1;
                sum[i] = countSubarray(c_bl);
            }
        }

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long tc = 0;
            int curr = l;
            while (curr <= r) {
                if ((curr / b_size) != (r / b_size) && hop[curr] <= r) {
                    tc += sum[curr];
                    curr = hop[curr];
                } else {
                    int be = last[curr];
                    int ie = min(be, r);
                    long long len = ie - curr + 1;
                    tc += countSubarray(len);
                    curr = ie + 1;
                }
            }
            ans.push_back(tc);
        }
        return ans;
    }
};