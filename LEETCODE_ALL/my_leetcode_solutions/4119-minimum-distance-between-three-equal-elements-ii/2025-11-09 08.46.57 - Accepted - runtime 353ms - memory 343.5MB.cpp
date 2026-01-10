class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]].push_back(i);
        }

        int min_distance = INT_MAX;

        for (auto& pair : freq) {
            vector<int>& index = pair.second;


            if (index.size() < 3) {
                continue;
            }

            for (int i = 0; i <= index.size() - 3; i++) {

                int i_val = index[i];
                int k_val = index[i+2];

                int dist = 2 * (k_val - i_val);

                min_distance = min(min_distance, dist);
            }
        }

        return min_distance == INT_MAX ? -1 : min_distance;
    }
};