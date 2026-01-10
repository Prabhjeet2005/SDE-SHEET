class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }

        cout << "BEFORE: ";
        for (auto& interval : mergedIntervals) {
            cout << interval[0] << "," << interval[1] << "\n";
        }
        // EDGE CASE
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        mergedIntervals.push_back(newInterval);

        cout << "After: ";
        for (auto& interval : mergedIntervals) {
            cout << interval[0] << "," << interval[1] << "\n";
        }

        while (i < intervals.size()) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }

        return mergedIntervals;
    }
};