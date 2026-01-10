class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int curr_row = grid.size();
        int curr_col = grid[0].size();

        // dp[r][c][third] = max_score to reach cell (r, c) with exactly 'third' cost
        vector<vector<vector<int>>> path_scores(
            curr_row, vector<vector<int>>(
                curr_col, vector<int>(k + 1, -1)
            )
        );

        path_scores[0][0][0] = 0;

        for (int r = 0; r < curr_row; ++r) {
            for (int c = 0; c < curr_col; ++c) {
                
                int cell_val = grid[r][c];
                int cell_score = 0;
                int cell_cost = 0;

                if (cell_val == 1) {
                    cell_score = 1;
                    cell_cost = 1;
                } else if (cell_val == 2) {
                    cell_score = 2;
                    cell_cost = 1;
                }

                for (int third = 0; third <= k; ++third) {
                    

                    if (r == 0 && c == 0) {

                        if (third > 0) path_scores[r][c][third] = -1;
                        continue;
                    }

                    int cost_from_prev = third - cell_cost;

                    if (cost_from_prev < 0) {
                        continue;
                    }

                    int score_from_up = (r > 0) ? path_scores[r - 1][c][cost_from_prev] : -1;
                    
                    int score_from_left = (c > 0) ? path_scores[r][c - 1][cost_from_prev] : -1;

                    if (score_from_up != -1 || score_from_left != -1) {
                        path_scores[r][c][third] = max(score_from_up, score_from_left) + cell_score;
                    }
                }
            }
        }

        const auto& last_cell_costs = path_scores[curr_row - 1][curr_col - 1];
        
        int max_score_at_end = *max_element(last_cell_costs.begin(), last_cell_costs.end());

        return max_score_at_end;
    }
};