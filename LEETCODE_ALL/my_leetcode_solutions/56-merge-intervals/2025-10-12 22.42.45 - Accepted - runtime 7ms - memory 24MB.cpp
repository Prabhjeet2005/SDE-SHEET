class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int currentInterval = 0, finalMax = 0;
        sort(intervals.begin(), intervals.end());
        
        while (currentInterval < intervals.size()) {
            if (ans.empty()) {
                ans.push_back(intervals[0]);
                currentInterval++;
                continue;
            }
            if (ans.back()[1] >= intervals[currentInterval][0]) {
                while (currentInterval < intervals.size() &&
                       ans.back()[1] >= intervals[currentInterval][0]) {

                    ans.back()[1] = max(ans.back()[1], intervals[currentInterval][1]);
                    currentInterval++;
                }
            } else {
                ans.push_back(intervals[currentInterval]);
                currentInterval++;
            }
        }

        return ans;
    }
};