class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for (int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[0].size(); col++) {
            bool currentPeak = true;
                int top = row - 1, right = col + 1, left = col - 1,
                    bottom = row + 1;
                if (top >= 0 && (mat[top][col] >= mat[row][col]))
                    currentPeak = false;
                if (left >= 0 && (mat[row][left] >= mat[row][col]))
                    currentPeak = false;
                if (right < mat[0].size() && (mat[row][right] >= mat[row][col]))
                    currentPeak = false;
                if (bottom < mat.size() && (mat[bottom][col] >= mat[row][col]))
                    currentPeak = false;

                if (currentPeak) {
                    return {row, col};
                }
            }
        }
        return {-1, -1};
    }
};