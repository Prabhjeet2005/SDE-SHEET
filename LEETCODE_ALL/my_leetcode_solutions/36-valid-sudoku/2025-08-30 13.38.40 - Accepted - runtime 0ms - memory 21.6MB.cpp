class Solution {
    void isPossible(vector < vector<char>> &board, int row, int col,
                    bool& isValid) {
        for (int i = 0; i < 9; i++) {
            if (i==row || col==i)
                continue;
            if (board[row][col] == board[row][i] ||
                board[row][col] == board[i][col]){
                isValid = false;return;}
        }
        int boxRow,boxCol;
        if(row >=0 && row < 3)boxRow=0;
        if(row >=3 && row < 6)boxRow=3;
        if(row >=6 && row < 9)boxRow=6;
        if(col >=0 && col < 3)boxCol=0;
        if(col >=3 && col < 6)boxCol=3;
        if(col >=6 && col < 9)boxCol=6;
        int cnt=0;
        for(int i=boxRow;i<boxRow+3;i++){
            for(int j=boxCol;j<boxCol+3;j++){
                
                if(board[row][col] == board[i][j]){
                    cnt++;
                }
                if(cnt>=2){isValid=false;return;}
            }
        }
        isValid = true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] - '0' >= 0 && board[i][j] - '0' <= 9) {
                    isPossible(board, i, j, isValid);
                    if (!isValid)
                        return false;
                }
            }
        }
        return isValid;
    }
};