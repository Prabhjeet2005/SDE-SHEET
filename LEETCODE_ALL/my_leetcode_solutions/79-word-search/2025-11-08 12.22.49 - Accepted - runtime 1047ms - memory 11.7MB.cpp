class Solution {
    bool find_word(vector<vector<char>>& board, string word,
                   vector<vector<bool>>& visited, int row, int col, int index) {

        if (index == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board[0].size()) {
            return false;
        }
        if (word[index] != board[row][col])
            return false;
        if (visited[row][col])
            return false;

        visited[row][col] = true;
        bool left = find_word(board, word, visited, row - 1, col, index + 1);
        bool top = find_word(board, word, visited, row, col - 1, index + 1);
        bool right = find_word(board, word, visited, row + 1, col, index + 1);
        bool down = find_word(board, word, visited, row, col + 1, index + 1);
        visited[row][col] = false;

        return left || top || right || down;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), 0));
        bool word_exists = false;
        // Anywhere from the grid
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != word[0] )continue;
                word_exists = word_exists || find_word(board, word, visited, i, j, 0);
            }
        return word_exists;
    }
};