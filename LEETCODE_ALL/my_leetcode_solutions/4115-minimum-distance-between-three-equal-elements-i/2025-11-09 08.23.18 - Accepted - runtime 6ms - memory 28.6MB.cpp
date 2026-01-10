class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // unordered_map<int, vector<int>> freq;

        // for (int i = 0; i < nums.size(); i++) {
        //     freq[nums[i]].push_back(i);
        // }

        int min_distance = INT_MAX;
        int curr_distance = INT_MAX;

        // for (auto& element : freq) {
        //     if (element.second.size() >= 3) {
        //         vector<int> nums = element.second;
        //         int first = element.second[0];
        //         int second = element.second[1];
        //         int third = element.second[2];
        //     }
        // }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if ((nums[i] == nums[j]) && (nums[j] == nums[k])) {
                        curr_distance = abs(i-j) +
                                        abs(j-k) +
                                        abs(i-k);

                        min_distance = min(min_distance, curr_distance);
                    }
                }
            }
        }
        return min_distance == INT_MAX ? -1 : min_distance;
    }
};