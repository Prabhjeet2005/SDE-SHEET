class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    private:

    bool solve(vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int k=1; k<=9; k++){
                        if(is_valid(board,i,j,k)){
                            board[i][j] = k + '0';
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false; // invalid path
                }
            }
        }
        return true;
    }

    bool is_valid(vector<vector<char>>&board,int row,int col,int curr_digit){
        for(int i=0; i<9;i++){
            if(board[row][i]==curr_digit+'0')return false;
            if(board[i][col]==curr_digit+'0')return false;
            if(board[3* (row/3) + i/3][3* (col/3) + i%3]==curr_digit+'0')return false;
        }
        return true;
    }
};