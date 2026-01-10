class Solution {

    void can_place(int row, int col, unordered_set<int>& left_right,
                   unordered_set<int>& right_left, unordered_set<int>& curr_col,
                   int n, int queens_placed, vector<vector<string>>& final_ans,
                   vector<string>& curr_board) {

        if (queens_placed == n) {
            final_ans.push_back(curr_board);
            return;
        }
        if (row >= n || col >= n) {
            return;
        }

        for (int i = 0; i < n; i++) {
            bool already_queen = left_right.count(row - i) ||
                                 right_left.count(row + i) || curr_col.count(i);
            if (already_queen) {
                continue;
            }
            curr_col.insert(i);
            left_right.insert(row - i);
            right_left.insert(row + i);
            curr_board[row][i] = 'Q';
            can_place(row + 1, i, left_right, right_left, curr_col, n,
                      queens_placed + 1, final_ans, curr_board);
            curr_board[row][i] = '.';
            curr_col.erase(i);
            left_right.erase(row - i);
            right_left.erase(row + i);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> final_ans;
        string initial = "";
        for (int i = 0; i < n; i++)
            initial += ".";
        vector<string> curr_board(n, initial);

        unordered_set<int> curr_col;
        unordered_set<int> left_right;
        unordered_set<int> right_left;
        can_place(0, 0, left_right, right_left, curr_col, n, 0, final_ans,
                  curr_board);

        return final_ans;
    }
};