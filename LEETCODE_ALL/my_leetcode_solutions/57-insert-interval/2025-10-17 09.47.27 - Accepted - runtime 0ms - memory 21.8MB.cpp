class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int i = 0;
        while (i < intervals.size()) {
            if (intervals[i][0] < newInterval[0]) {
                mergedIntervals.push_back(intervals[i]);
            } else {
                break;
            }
            i++;
        }
        if (mergedIntervals.size() > 0 && (mergedIntervals.back()[1] >= newInterval[0] ||
            mergedIntervals.back()[0] >= newInterval[0])) {
            mergedIntervals.back()[0] =
                min(mergedIntervals.back()[0], newInterval[0]);
            mergedIntervals.back()[1] =
                max(mergedIntervals.back()[1], newInterval[1]);
        } else {
            mergedIntervals.push_back(newInterval);
        }
        while (i < intervals.size()) {
            if (mergedIntervals.back()[1] >= intervals[i][0] ||
                mergedIntervals.back()[0] >= intervals[i][0]) {
                mergedIntervals.back()[0] =
                    min(mergedIntervals.back()[0], intervals[i][0]);
                mergedIntervals.back()[1] =
                    max(mergedIntervals.back()[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
            i++;
        }

        return mergedIntervals;
    }
};