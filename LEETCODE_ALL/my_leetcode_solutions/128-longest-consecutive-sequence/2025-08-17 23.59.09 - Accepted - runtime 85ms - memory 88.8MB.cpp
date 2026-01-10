class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set;

        for (auto& it : nums)
            set.insert(it);

        int currentSequence = 1, longestSequence = 1;
        if (nums.size() <= 1) {
            return nums.size();
        }

        for (auto setIterator: set) {
            if (set.find(setIterator - 1) == set.end()) {
                int cnt = 1;
                currentSequence = 1;
                while (set.find(setIterator + cnt) != set.end()) {
                    currentSequence++;
                    longestSequence = max(longestSequence, currentSequence);
                    cnt++;
                }
            }
        }

        return longestSequence;
    }
};